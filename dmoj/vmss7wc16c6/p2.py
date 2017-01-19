n, m = [int(_) for _ in input().split()]
a = [list(input()) for j in range(n)]

assert(1 <= n <= 100)
assert(1 <= m <= 100)
for i in a:
    tmpList = list(set(list(i)))
    assert(tmpList in [['.'], ['.', 'X'], ['X', '.'], ['X']])

def floodFill(x, y, z):
    if a[y][x] != '.':
        return
    a[y][x] = z
    floodFill(x-1, y, z)
    floodFill(x+1, y, z)
    floodFill(x, y+1, z)
    floodFill(x, y-1, z)

floodCnt = 1
for y in range(n):
    for x in range(m):
        if a[y][x] == '.':
            floodFill(x, y, str(floodCnt))
            floodCnt += 1

'''
for y in range(n):
    print(''.join(a[y]))
'''

bestCnt = -1
bestX = 0
bestY = 0
bestList = []
for y in range(n):
    for x in range(m):
        if a[y][x] == 'X':
            currList = []
            for cy in range(y-1,y+2,2):
                if 0 <= cy < n:
                    currList.append(a[cy][x])
            for cx in range(x-1,x+2,2):
                if 0 <= cx < m:
                    currList.append(a[y][cx])
            #print(x, y, currList)
            currList[:] = [_ for _ in currList if _ not in ['.', 'X']]
            currList = list(set(currList))
            currList.sort()
            if len(currList) > 1 and len(currList) > bestCnt:
                bestCnt = len(currList)
                bestX = x
                bestY = y
                bestList = currList[:]

if bestCnt == -1:
    print(-1)
else:
    print(bestCnt)
    print(bestX, bestY)
    s = ""
    for i in bestList:
        s += i + " "
    print(s)
