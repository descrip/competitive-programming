from math import *
n = int(input())
for i in range(2, int(ceil(n**0.5))+1):
    while n % i == 0:
        n /= i
        print(i)
if n != 1:
    print(int(n))
