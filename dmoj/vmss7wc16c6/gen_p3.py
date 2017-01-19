'''
from random import randint, shuffle
N, M = [int(_) for _ in input().split()]
used = [1]
edges = []
for i in range(2, N+1):
    d = [i, used[randint(0, len(used)-1)]]
    d.sort()
    edges.append((d[0], d[1]))
    used.append(i)
setEdges = set(edges)
while len(setEdges) != M:
    a = [randint(1, N), randint(1, N)]
    a.sort()
    b = (a[0], a[1])
    if b not in setEdges:
        edges.append(b)
        setEdges.add(b)
setEdges = list(setEdges)
shuffle(setEdges)
print(N, M)
for i in setEdges:
    if (randint(0,1)):
        print(i[0], i[1])
    else:
        print(i[1], i[0])
'''
'''
n = 99999
print(n, n)
print(1, n//3+1)
print(1, 2*n//3+1)
for i in range(2,n//3+1):
    print(i, 1)
for i in range(n//3+2,2*n//3+1):
    print(n//3+1,i)
print(n//3+2,2*n//3)
print(n//3+2,2*n//3-1)
print(n//3+1, 2*n//3+1)
for i in range(2*n//3+2,n+1):
    print(i, 2*n//3+1)
'''

'''
import igraph
from random import randint
N,M = [int(_) for _ in input().split()]
g = igraph.Graph.Erdos_Renyi(n=N, m=M)
l = g.get_edgelist()
print(N, M)
for i in l:
    print(i[0]+1, i[1]+1)
'''

'''
from random import randint
N = int(input())
A = set((randint(0, i), i+1) for i in range(N-1)) | set((i,j) for i in range(N) for j in range(i) if randint(0,1))
print(N, len(A))
for i in A:
    print(i[0], i[1])
'''

from random import shuffle
N = int(input())
A = [i for i in range(1, N+1)]
shuffle(A)
print(N, len(A)-1)
for i in range(len(A)-1):
    print(A[i], A[i+1])
