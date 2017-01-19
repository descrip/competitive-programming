x, y = [int(_) for _ in input().split()]
cnt = [0] * 10
for i in range(x, y+1):
    s = str(i)
    for c in s:
        cnt[int(c)] += 1
print(cnt)
