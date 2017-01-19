import sys
n,m,k = [int(_) for _ in input().split()]

def square(a,y,x):
    try:
        if a[y][x] == 1 and a[y+1][x] == 1 and a[y][x+1] == 1 and a[y+1][x+1] == 1:
            return True
    except:
        pass
    try:
        if a[y][x] == 1 and a[y-1][x] == 1 and a[y][x-1] == 1 and a[y-1][x-1] == 1:
            return True
    except:
        pass
    try:
        if a[y][x] == 1 and a[y-1][x] == 1 and a[y-1][x+1] == 1 and a[y][x+1] == 1:
            return True
    except:
        pass
    try:
        if a[y][x] == 1 and a[y+1][x] == 1 and a[y+1][x-1] == 1 and a[y][x-1] == 1:
            return True
    except:
        pass
    return False

a = [[0 for j in range(m)] for i in range(n)]

for i in range(1,k+1):
    x,y = [int(_) for _ in input().split()]
    a[x-1][y-1] = 1
    if square(a,x-1,y-1):
        print(i)
        sys.exit(0)
print(0)
