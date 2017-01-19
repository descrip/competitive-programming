n,m,a,b = [int(_) for _ in input().split()]
adj = [[-1 for i in range(n)] for j in range(n)]
for i in range(m):
    x,y,z = [int(_) for _ in input().split()]
    x -= 1
    y -= 1
    adj[x][y] = z;
dist = [0xfffffff] * n
vis = [False] * n
a -= 1
b -= 1
dist[a] = 0
while True:
    u = -1
    bestDist = 0xfffffff
    for i in range(n):
        if not vis[i] and dist[i] < bestDist:
            u = i
            bestDist = dist[i]
    #print(u, bestDist)
    if bestDist == 0xfffffff:
        break
    for v in range(n):
        if not vis[v] and adj[u][v] != -1 and dist[v] > dist[u] + adj[u][v]:
            dist[v] = dist[u] + adj[u][v]
    vis[u] = True
print(dist[b])
