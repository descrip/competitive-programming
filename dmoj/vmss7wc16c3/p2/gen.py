import random
n,m = [int(_) for _ in input().split()]
print(n, m, random.randint(1,n), random.randint(1,n))
for i in range(m):
    print(random.randint(1,n), random.randint(1,n))
