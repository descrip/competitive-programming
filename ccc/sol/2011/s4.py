A = []
for i in range(2):
    A.append([int(_) for _ in input().strip().split()])
C = 0
A.append([(0,),(1,0),(2,0),(3,2,1,0),(4,0),(5,4,1,0),(6,4,2,0),(7,6,5,4,3,2,1,0)])
for i in range(8):
    for j in A[2][i]:
        D = min(A[1][i],A[0][j])
        A[1][i] -= D
        A[0][j] -= D
        C += D
print(C)
