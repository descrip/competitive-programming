import sys, copy
n,m = [int(_) for _ in input().split()]
a = []
for i in range(n):
    a.append(list(input().strip()[:m]))

def getA(a,x,y):
    l = []
    if y > 0:
        l.append(a[y-1][x])
    if x > 0:
        l.append(a[y][x-1])
    return l

def recur(a,sx,sy):
    for y in range(sx,n):
        for x in range(sy,m):
            if a[y][x] == '.':
                l = getA(a,x,y)
                if l.count('W') == 1 and l.count('B') == 1:
                    return
                for i in l:
                    if i == 'W':
                        a[y][x] = 'B'
                        break
                    elif i == 'B':
                        a[y][x] = 'W'
                        break
                else:
                    a[y][x] = 'B'
                    recur(copy.deepcopy(a),x,y)
                    a[y][x] = 'W'
                    recur(copy.deepcopy(a),x,y)
    for y in range(n):
        print(''.join(a[y]))
    sys.exit(0)

recur(a,0,0)
