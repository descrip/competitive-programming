import sys

sys.setrecursionlimit(1000000000)
T = int(input())

def recur(x,y):
    global a,r,c,v

    if x < 0 or x >= c or y < 0 or y >= r or v[y][x] == True or a[y][x] == '*':
        return 1000000000
    else:
        v[y][x] = True
        if x == c-1 and y == r-1:
            return 1
        elif a[y][x] == '-':
            return min(recur(x-1,y), recur(x+1,y)) + 1
        elif a[y][x] == '|':
            return min(recur(x,y-1), recur(x,y+1)) + 1
        elif a[y][x] == '+':
            return min(min(recur(x,y-1), recur(x,y+1)), min(recur(x-1,y), recur(x+1,y))) + 1

for t in range(T):
    r = int(input())
    c = int(input())
    a = [list(input()) for i in range(r)]
    v = [[False for i in range(c)] for j in range(r)]
    ans = recur(0,0)
    if ans >= 1000000000:
        print(-1)
    else:
        print(ans)
