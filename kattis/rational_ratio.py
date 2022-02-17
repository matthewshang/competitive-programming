import math

# Date: 2022-01-28
# Source: NCNA 2018

num, repeat = input().split(' ')
repeat = int(repeat)
end = int(num[-repeat:])
inte = int(num[:num.find('.')])
if num[-repeat - 1] == '.':
    mid = 0
else:
    mid = int(num[num.find('.') + 1:-repeat])
after = len(num) - num.find('.') - 1
shift = pow(10, after - repeat)

nines = int('9' * repeat)
top = inte * nines * shift + mid * nines + end
bot = nines * shift
g = math.gcd(top, bot)
top //= g
bot //= g
print(f'{top}/{bot}')