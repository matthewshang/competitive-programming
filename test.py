import filecmp
import io
import os
import shutil
import subprocess
import sys
import zipfile
from contextlib import contextmanager
from os.path import isfile, join

import requests


@contextmanager
def cd(newdir):
    prevdir = os.getcwd()
    os.chdir(os.path.expanduser(newdir))
    try:
        yield
    finally:
        os.chdir(prevdir)


def compare(file1, file2):
    with open(file1, 'r') as f1, open(file2, 'r') as f2:
        for line1, line2 in zip(f1, f2):
            if line1 != line2:
                return False
    return True


def download_tests(problem, diff, date):
    url = 'http://www.usaco.org/current/data/{}_{}_{}.zip'.format(
        problem, diff, date)
    dirs = [d for d in os.listdir('build') if os.path.isdir(join('build', d))]
    if problem in dirs:
        print(problem + ' is already downloaded')
        return

    print('Downloading from ' + url)
    r = requests.get(url)
    z = zipfile.ZipFile(io.BytesIO(r.content))
    z.extractall(join('build', problem))


def do_tests(problem):
    print('Testing problem {}'.format(problem))
    with cd('build'):
        files = [f for f in os.listdir(problem) if isfile(join(problem, f))]
        name = problem + '.in'
        copy_name = problem + '.tmp.in'
        shutil.copyfile(name, copy_name)

        for i in range(1, int(len(files) / 2) + 1):
            shutil.copyfile(join(problem, '{}.in'.format(i)), name)
            subprocess.call(problem + '.exe')

            same = compare(join(problem, '{}.out'.format(i)), problem + '.out')
            print('test {}: {}'.format(i, 'ok' if same else 'fail'))

        shutil.copyfile(copy_name, name)
        os.remove(copy_name)


if __name__ == '__main__':
    op = sys.argv[1]
    if op == 'dl':
        download_tests(sys.argv[2], sys.argv[3], sys.argv[4] if len(sys.argv) > 4 else '')
    elif op == 'cl':
        shutil.rmtree('build')
        os.makedirs('build')
    elif op == 'mk':
        path = join('build', sys.argv[2] + '.in')
        if not os.path.exists(path):
            with open(path, 'w'):
                pass
    else:
        do_tests(sys.argv[1])
