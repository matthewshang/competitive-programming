# Date: 2022-01-28
# Source: NCNA 2018

n = int(input())

sum = 1
fac = 1
for i in range(1, min(25, n) + 1):
    fac *= i
    sum += 1 / fac
print(sum)