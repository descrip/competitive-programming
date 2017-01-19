from math import *
import random
n = int(input())
print(n)
prev = set()
maxX = max(random.randint(5,10**3), ceil(n**0.5))
maxY = max(random.randint(5,10**3), ceil(n**0.5))
for i in range(n):
    while True:
        a = (random.randint(0,maxX), random.randint(0,maxY))
        if a in prev:
            continue
        prev.add(a)
        print(a[0], a[1])
        break
