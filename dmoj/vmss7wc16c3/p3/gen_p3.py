from random import *
N, M, Q = [int(_) for _ in input().split()]
A = [ (i,j) for i in range(N) for j in range(i) if randint(0,1) ]
shuffle(A)
print(N, min(M, len(A)), randint(1,N), Q)
for i in range(min(M, len(A))):
    print(A[i][0]+1, A[i][1]+1, randint(1, 2000))
L = [i for i in range(1, N+1)]
shuffle(L)
for i in range(Q):
    print(L[i])
