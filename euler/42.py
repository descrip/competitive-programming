#c++ input too hard
from math import *

s = input().split('","')
s[0] = s[0][1:]
s[-1] = s[-1][:-1]
ans = 0

t = []
for i in range(1,20):
    t.append(0.5 * i * (i+1))

for i in s:
    curr = 0
    for c in i:
        curr += ord(c) - 64
    if curr in t:
        ans += 1

print(ans)
