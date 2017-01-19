import sys

n,m,a,b = [int(_) for _ in input().split()]
a -= 1
b -= 1
adj = [[] for j in range(n)]
for i in range(m):
    x,y = [int(_) for _ in input().split()]
    x -= 1
    y -= 1
    adj[x].append(y)
    adj[y].append(x)
vis = [False] * n

def dfs(pos):
    global b
    if vis[pos]:
        return
    vis[pos] = True
    if pos == b:
        print("GO SHAHIR!")
        sys.exit(0)
    for i in adj[pos]:
        dfs(i)

dfs(a)
print("NO SHAHIR!")
