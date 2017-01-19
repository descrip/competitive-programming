#p3_1 - p3_5, p3_7 - p3_10
from random import randint
N = int(input())
A = [(randint(0, i), i+1) for i in range(N-1)]
print(N)
for i in A:
    print(i[0]+1, i[1]+1)

#p3_6
'''
from random import shuffle
N = int(input())
S = [i for i in range(1, N+1)]
shuffle(S)
print(N)
for i in range(N-1):
    print(S[i], S[i+1])
'''
