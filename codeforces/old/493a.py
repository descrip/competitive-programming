teams = [input(),input()]
n = int(input())
yel = []
red = []

def convert(t,n):
    global teams
    s = ""
    if t == 'a':
        s += teams[1] + ' '
    else:
        s += teams[0] + ' '
    return s + n

for foul in range(n):
    a = input().split()
    temp = convert(a[1],a[2])
    if a[-1] == 'y':
        if temp in yel:
            yel.remove(temp)
            red.append(temp)
            print(temp + ' ' + a[0])
        elif temp in red:
            continue
        else:
            yel.append(temp)
    elif a[-1] == 'r':
        temp = convert(a[1],a[2])
        if temp in red:
            continue
        else:
            print(temp + ' ' + a[0])
            red.append(temp)
