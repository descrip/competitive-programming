n = int(input())
for _ in range(n):
    d = [int(_) for _ in input().split()]
    ok = False
    if d[0] < 1989:
        ok = True
    elif d[0] == 1989:
        if d[1] < 2:
            ok = True
        elif d[1] == 2:
            if d[2] <= 27:
                ok = True
    if ok:
        print("Yes")
    else:
        print("No")
