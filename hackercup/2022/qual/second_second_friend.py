import sys

def solve(tc: int):
    R, C = map(int, sys.stdin.readline().split())
    g = [list(sys.stdin.readline().strip()) for _ in range(R)]

    def exec_adjacent(i: int, j: int, func):
        for di, dj in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            ii, jj = i + di, j + dj
            if ii >= 0 and ii < R and jj >= 0 and jj < C:
                func(ii, jj)

    def count_adjacent(i: int, j: int, pred) -> int:
        count = 0
        def counter(ii, jj):
            nonlocal count
            if pred(g[ii][jj]):
                count += 1
        exec_adjacent(i, j, counter)
        return count
    
    def is_happy(i: int, j: int) -> bool:
        return count_adjacent(i, j, lambda c: c == '^') >= 2
    
    def can_be_happy(i: int, j: int) -> bool:
        return count_adjacent(i, j, lambda c: c != '#') >= 2

    stack = []
    for i in range(R):
        for j in range(C):
            if g[i][j] == '^' and not is_happy(i, j):
                stack.append((i, j))

    visited = set()
    while stack:
        i, j = stack.pop()
        if (i, j) in visited:
            continue
        visited.add((i, j))
        g[i][j] = '^'

        def visit(ii, jj):
            if g[ii][jj] == '.' and can_be_happy(ii, jj):
                stack.append((ii, jj))
        exec_adjacent(i, j, visit)

    ok = True
    for i in range(R):
        for j in range(C):
            if g[i][j] == '^' and not is_happy(i, j):
                ok = False
    print(f"Case #{tc}: {'Possible' if ok else 'Impossible'}")
    if ok:
        print('\n'.join(''.join(row) for row in g))

T = int(input())
for tc in range(1, T + 1):
    solve(tc)