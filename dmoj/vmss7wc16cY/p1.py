import sys
n,m = [int(_) for _ in input().split()]
s = input() == "u"
adj = [[] for i in range(N)]
for i in range(m):
    x, y = [int(_) for _ in input().split()]
    x -= 1
    y -= 1
    adj[x].append(y)
    if s:
        adj[y].append(x)
a,b = [int(_) for _ in input().split()]
a -= 1
b -= 1
vis = [False for i in range(N)]

def dfs(pos):
    if vis[pos]:
        return
    vis[pos] = True
    if pos == b:
        print("Yes")
        sys.exit(0)
    for i in adj[pos]:
        dfs(i)

dfs(a)
print("No")
