#x-c y-r
c, r = [int(_) for _ in input().split()]
x, y = 0, 0 
while True:
    a, b = [int(_) for _ in input().split()]
    if a == 0 and b == 0:
        break
    if a < 0:
        x = max(0,x+a)
    elif a > 0:
        x = min(c,x+a)
    if b < 0:
        y = max(0,y+b)
    else:
        y = min(r,y+b)
    print(x,y)
