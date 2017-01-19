n = int(input())
l = []
for i in range(n):
    x, y = [int(_) for _ in input().split()]
    l.append((x, y))
print(n)
for i in reversed(l):
    print(i[0], i[1])
