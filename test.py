import filecmp
import glob
import io
import os
import platform
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


extension = '.exe' if platform.system() == 'Windows' else '.o'


def file_is_empty(path):
    return os.stat(path).st_size == 0


def compare(file1, file2):
    if file_is_empty(file1) or file_is_empty(file2):
        return False
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


def find_and_compile(problem):
    target = None
    for filename in glob.iglob('**/*.cpp', recursive=True):
        name = os.path.splitext(os.path.basename(filename))[0]
        if name == problem:
            target = filename
            break

    compiler = 'g++' if platform.system() == 'Windows' else 'g++-8'
    out = join('build', problem + extension)
    call = compiler + ' -O2 -lm -std=c++0x -Wl,-stack_size -Wl,0x10000000 {} -o {}'.format(target, out)
    return subprocess.call(call, shell=True)


def do_tests(problem):
    print('Testing problem {}'.format(problem))
    if find_and_compile(problem) != 0:
        return
    with cd('build'):
        files = [f for f in os.listdir(problem) if isfile(join(problem, f))]
        name = problem + '.in'
        copy_name = problem + '.tmp.in'
        shutil.copyfile(name, copy_name)

        for i in range(1, int(len(files) / 2) + 1):
            shutil.copyfile(join(problem, '{}.in'.format(i)), name)
            if subprocess.call(join('.', problem + extension)) != 0:
                print('Non-zero status code')
                break

            same = compare(join('.', problem, str(i) + '.out'),
                           join('.', problem + '.out'))
            print('test {}: {}'.format(i, 'ok' if same else 'fail'))

        shutil.copyfile(copy_name, name)
        os.remove(copy_name)


def set_in(problem, index):
    path = join('build', problem + '.in')
    if os.path.exists(path):
        os.remove(path)
    name = str(index) + '.in'
    if not is_downloaded(problem):
        print(problem + ' is not downloaded')
    else:
        shutil.copyfile(join('build', problem, name), path)


if __name__ == '__main__':
    op = sys.argv[1]
    if op == 'dl':
        download_tests(sys.argv[2], sys.argv[3], sys.argv[4] if len(sys.argv) > 4 else '')
        set_in(sys.argv[2], 1)
    elif op == 'cl':
        shutil.rmtree('build')
        os.makedirs('build')
    elif op == 'set':
        set_in(sys.argv[2], 1 if len(sys.argv) < 4 else sys.argv[3])
    else:
        if not is_downloaded(sys.argv[1]):
            print(sys.argv[1] + ' is not downloaded')
        else:
            do_tests(sys.argv[1])
