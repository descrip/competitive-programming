from math import ceil
N = int(input())
assert(1 <= N <= 100)
A = []
for i in range(N):
    x, y = [int(_) for _ in input().split()]
    assert(0 <= x <= 1000)
    assert(0 <= y <= 1000)
    A.append((x, y));
A.append(A[0])
ans = 0
for i in range(len(A)-1):
    ans += A[i][0] * A[i+1][1]
for i in range(1,len(A)):
    ans -= A[i][0] * A[i-1][1]
print(ceil(abs(ans/2)))
