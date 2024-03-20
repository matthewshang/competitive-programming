import os
from datetime import datetime
from dataclasses import dataclass

from rich.console import Console
from rich.table import Table


@dataclass
class Solution:
    """Data associated with a solved problem."""
    filename: str
    date: str = ""
    source: str = ""
    notes: str = ""


def extract_date(path, contents):
    for line in contents:
        if "Date:" in line:
            start = line.find(":") + 2
            return line[start:start + 10]
    return datetime.fromtimestamp(os.path.getmtime(path)).strftime('%Y-%m-%d')


def extract_source(path, contents):
    for line in contents:
        if "* Source:" in line:
            start = line.find(":") + 2
            return line[start:].strip()
    return None


def extract_notes(contents):
    notes = []
    note_begin = None
    for linenum, line in enumerate(contents):
        if "Notes:" in line or "Summary:" in line:
            note_begin = linenum
            break

    if note_begin:
        first_line = contents[note_begin]
        notes.append(first_line[first_line.find(":") + 2:].strip())
        note_begin += 1
        while note_begin < len(contents) and "*/" not in contents[note_begin]:
            line = contents[note_begin]
            notes.append(line[line.find("*") + 2:].strip())
            note_begin += 1
    return " ".join(notes)


def parse_solution(path):
    with open(path, "r") as f:
        contents = f.readlines()

    return Solution(filename=os.path.basename(path),
                    date=extract_date(path, contents),
                    source=extract_source(path, contents),
                    notes=extract_notes(contents))


def gather(path=None):
    solutions = []
    with os.scandir(path) as it:
        for entry in it:
            if entry.is_dir(follow_symlinks=False):
                sub_solutions = gather(entry.path)
                solutions.extend(sub_solutions)
            elif entry.is_file() and entry.name.endswith(".cpp"):
                solutions.append(parse_solution(entry.path))
    return solutions


def main():
    solutions = gather(os.environ.get("COMPETITIVE_PROGRAMMING_ROOT"))
    solutions.sort(key=lambda s: s.date, reverse=True)

    table = Table(show_header=True, header_style="bold magenta", leading=True)
    table.add_column("Date")
    table.add_column("Source", width=10)
    table.add_column("Name", width=20)
    table.add_column("Notes")
    for sol in solutions:
        if sol.source:
            table.add_row(sol.date, sol.source, sol.filename, sol.notes)

    console = Console()
    with console.pager(styles=True):
        console.print(f'{len(solutions)} problems')
        console.print(table)


if __name__ == "__main__":
    main()
