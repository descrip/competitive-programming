n = int(input())
d = {}
for _ in range(n):
    old, new = input().strip().split()
    if old not in d.keys():
        for i in d:
            if d[i] == old:
                d[i] = new
                break
        else:
            d[old] = new
    else:
        d[old] = new
print(len(d))
for i in d:
    print(i,d[i])
