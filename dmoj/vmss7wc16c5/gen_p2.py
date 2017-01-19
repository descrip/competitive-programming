#p1_2
'''
n = int(input())
print(n)
for i in range(1,n+1):
    print(2*i, 1)
'''

#p2_8
'''
n = int(input())
print(n)
for i in range(1,n):
    print(i, 10)
print(1000, 3)
'''

#everything else
from random import randint
n = int(input())
print(n)
for i in range(n):
    print(randint(1, 10**8), randint(1, 10**7))
