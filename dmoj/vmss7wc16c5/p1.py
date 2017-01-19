from math import *
L, x = [int(_) for _ in input().split()]
assert(1 <= L <= 900)
assert(1 <= x <= 50)
print(L*(x-1))
