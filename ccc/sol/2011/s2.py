C = int(input())
A = [[],[]]
for i in range(2):
    for j in range(C):
        A[i].append(input())
Z = 0
for i in range(C):
    if A[1][i] == A[0][i]:
        Z += 1
print(Z)
