while True:
    n = int(input())
    if n == 0:
        break
    ok = True
    
    a = [[int(_) for _ in input().strip().split()] for i in range(n)]
    
    #check main
    s = set()
    for y in range(n):
        for x in range(n):
            s.add(a[y][x])
    t = list(s)
    for i in s:
        if not 0 <= i <= n:
            ok = False
            break
    if not ok:
        print('no')
        continue
    for i in range(len(s)-1):
        for j in range(i+1,len(s)):
            if a[t[i] - 1][t[j] - 1] not in s:
                ok = False
                break
        else:
            continue
        break
    if not ok:
        print('no')
        continue
    
    #check assoc
    for y in range(n):
        for x in range(n):
            for z in range(n):
                if a[x][a[y][z] - 1] != a[a[x][y] - 1][z]:
                    ok = False
                    break
            else:
                continue
            break
        else:
            continue
        break
    if not ok:
        print('no')
        continue

    #check ident
    m = list(range(1,n+1))
    possi = []
    for y in range(n):
        if a[y] == m:
            for y2 in range(n):
                if a[y2][y] != m[y2]:
                    break
            else:
                possi.append(y+1)
                break
    if len(possi) == 0:
        print('no')
        continue
    
    #check inv
    for i in possi:
        for y in range(n):
            for x in range(n):
                if a[y][x] == i and a[x][y] == i:
                    break
            else:
                break
            continue
        else:
            break
        continue
    else:
        ok = False
    
    if not ok:
        print('no')
        continue
    else:
        print('yes')
