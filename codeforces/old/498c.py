x1, y1 = [int(_) for _ in input().split()]
x2, y2 = [int(_) for _ in input().split()]
n = int(input())
ans = 0
for i in range(n):
    a, b, c = [int(_) for _ in input().split()]
    zy1 = a * x1 + b * y1 + c
    zy2 = a * x2 + b * y2 + c
    if (zy1 > 0 and zy2 < 0) or (zy1 < 0 and zy2 > 0):
        ans += 1
print(ans)
