import sys
N,M,A,B = [int(_) for _ in input().split()]
A -= 1
B -= 1
adj = [[] for i in range(N)]
for i in range(M):
    x, y = [int(_) for _ in input().split()]
    x -= 1
    y -= 1
    adj[x].append(y)
    adj[y].append(x)
vis = [False for i in range(N)]

def dfs(pos):
    if vis[pos]:
        return
    vis[pos] = True
    if pos == B:
        print("GO SHAHIR!")
        sys.exit(0)
    for i in adj[pos]:
        if not vis[i]:
            dfs(i)

dfs(A)
print("NO SHAHIR!")
