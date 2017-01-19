n,m = [int(_) for _ in input().split()]
d = [[] for i in range(n+1)]
for i in range(m):
    a,b,c = [int(_) for _ in input().split()]
    d[a].append((b,c))
    d[b].append((a,c))
q = int(input())

def query(d,a,b):
    if a > b:
        a,b = b,a
    l = []
    for i in range(len(d[a])):
        l.append(d[a][i])
    cnt = 0
    v = [False] * (n+1)
    while len(l) > 0:
        if l[0][0] == b:
            cnt += 1
            del l[0]
            continue
        for i in range(len(d[l[0][0]])):
            if v[d[l[0][0]][i][0]] == False and d[l[0][0]][i][1] == l[0][1]:
                l.append(d[l[0][0]][i])
                if d[l[0][0]][i][0] != b:
                    v[d[l[0][0]][i][0]] = True
        del l[0]
    return cnt

for qu in range(q):
   a,b = [int(_) for _ in input().split()]
   print(query(d,a,b))
