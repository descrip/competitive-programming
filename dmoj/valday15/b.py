c,m = [int(_) for _ in input().split()]
p,r = [],[]
for i in range(c):
    p.append(tuple([int(_) for _ in input().split()]))
    r.append((p[i][0]/p[i][1],i))
r.sort()
r.reverse()
ans = 0
while p[r[0][1]][1] <= m:
    ans += p[r[0][1]][0]
    m -= p[r[0][1]][1]
    print(r[0],p[r[0][1]])
    del r[0]
print(ans)
