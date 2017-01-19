import sys
n = int(input())
minX = minY = 0xfffffff
maxX = maxY = 0
for i in range(n):
    x, y = [int(_) for _ in input().split()]
    minX = min(minX, x)
    maxX = max(maxX, x)
    minY = min(minY, y)
    maxY = max(maxY, y)
print((maxY-minY)*(maxX-minX))
