import sys
sys.setrecursionlimit(20005)

n = int(input())
assert(1 <= n <= 10**4)
adj = [[] for i in range(n)]
for i in range(n-1):
    x, y = [int(_) for _ in input().split()]
    assert(1 <= x <= n)
    assert(1 <= y <= n)
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
vis = [False] * n
print(dfs(tmp)[0])
