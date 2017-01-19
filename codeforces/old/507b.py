from math import *
r,x1,y1,x2,y2 = [int(_) for _ in input().split()]
print(ceil(((x2 - x1)**2 + (y2 - y1)**2)**0.5 / (2 * r)))
