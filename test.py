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


def is_downloaded(problem):
    return problem in [d for d in os.listdir('build') if os.path.isdir(join('build', d))]


def download_tests(problem, diff, date):
    url = 'http://www.usaco.org/current/data/{}_{}_{}.zip'.format(
        problem, diff, date)
    if is_downloaded(problem):
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
            if subprocess.call(problem + '.exe') != 0:
                print('Non-zero status code')
                break

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
    elif op == 'set':
        path = join('build', sys.argv[2] + '.in')
        if os.path.exists(path):
            os.remove(path)
        name = '1.in' if len(sys.argv) < 4 else sys.argv[3] + '.in'
        if not is_downloaded(sys.argv[2]):
            print(sys.argv[2] + ' is not downloaded')
        else:
            shutil.copyfile(join('build', sys.argv[2], name), path)
    else:
        do_tests(sys.argv[1])
