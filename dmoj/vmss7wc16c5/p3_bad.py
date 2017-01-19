n = int(input())
adj = [[] for i in range(n)]
for i in range(n-1):
    x, y = [int(_) for _ in input().split()]
    x -= 1
    y -= 1
    adj[x].append(y)
    adj[y].append(x)
vis = [False] * n

def dfs(pos):
    vis[pos] = True
    ret = (-1, pos)
    for i in adj[pos]:
        if not vis[i]:
            ret = max(ret, dfs(i))
    return (ret[0]+1, ret[1])

tmp = dfs(0)[1]
