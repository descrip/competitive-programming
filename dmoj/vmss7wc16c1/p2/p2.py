import sys
n = int(input())
l = []
for i in range(n):
    l.append(int(input()))
for i in range(n, -1, -1):
    cnt = 0
    for j in l:
        if i == j:
            cnt += 1
    if cnt == i:
        print(i)
        sys.exit(0)
print("Paradox!")
