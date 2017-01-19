a = sum([int(_) for _ in input().split()])
b = sum([int(_) for _ in input().split()])
n = int(input())
for i in range(n):
    if a > 0:
        a -= 5
    elif b > 0:
        b -= 10
if a > 0 or b > 0:
    print("NO")
else:
    print("YES")
