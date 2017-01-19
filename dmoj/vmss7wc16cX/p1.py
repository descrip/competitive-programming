n,m = [int(_) for _ in input().split()]
vis = [False] * n
adj = [[] for i in range(n)]

def recur(n):
    if vis[n]:
        return
    vis[n] = True
    for i in adj[n]:
        recur(i)

for i in range(m):
    x, y= [int(_) for _ in input().split()]
    adj[x].append(y)
    adj[y].append(x)

recur(0)
if m == n-1 and False not in vis:
    print("It's a tree!")
else:
    print("It's not a tree!")

