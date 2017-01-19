from random import randint
n, m = [int(_) for _ in input().split()]
print(n, m)
a = [['X' for x in range(m)] for y in range(n)]
for i in range(randint(int((n*m)**(3/5)), n*m)):
    a[randint(1,n-2)][randint(1,m-2)] = '.'
for i in a:
    print(''.join(i))
