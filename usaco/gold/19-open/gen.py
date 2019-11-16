import random

N = 400
K = 399

with open('snakes.in', 'w') as f:
    f.write(f'{N} {K}\n')
    for i in range(N):
        f.write(str(random.randint(0, 1000000)) + ' ')
    f.write('\n')
