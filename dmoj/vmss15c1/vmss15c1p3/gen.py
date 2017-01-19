from random import randint

def f():
    return randint(-10**1,10**1)

xh,yh,xs,ys = [f() for _ in range(4)]
print(xh,yh,xs,ys)
n = randint(0,5)
print(n)

for i in range(n):
    while True:
        a,b,c = [f() for _ in range(3)]
        if a*xh + b*yh + c != 0 and a*xs + b*ys + c != 0:
            print(a,b,c)
            break
