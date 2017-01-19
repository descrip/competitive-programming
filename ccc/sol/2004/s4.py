s = [0] + [int(_) for _ in input().split()]
e = [0] + [int(_) for _ in input().split()]

#forward top left
d = [1,3,2]
best = 99999

def turnUp(d):
    temp = d[0]
    d[0] = d[1]
    d[1] = temp * -1
    
def turnLeft(d):
    temp = d[0]
    d[0] = d[2]
    d[2] = temp * -1

while True:
    l, t = input().split()
    l = int(l)
    
    da = abs(d[0])
    n = s[:]
    n[da] += (d[0] // abs(d[0])) * l
    
    if min(s[da],n[da]) <= e[da] <= max(s[da],n[da]):
        temp = 0
        for i in range(1,4):
            if da != i:
                temp += (e[i] - s[i]) ** 2
        best = min(best,temp ** 0.5)
    else:
        temp = 0
        for i in range(3):
            temp += (s[abs(d[i])] - e[abs(d[i])]) ** 2
        best = min(best,temp ** 0.5)
        temp = 0
        for i in range(3):
            temp += (n[abs(d[i])] - e[abs(d[i])]) ** 2
        best = min(best,temp ** 0.5)
    
    s = n[:]
    
    if t == 'L':
        turnLeft(d)
    elif t == 'R':
        for _ in range(3):
            turnLeft(d)
    elif t == 'U':
        turnUp(d)
    elif t == 'D':
        for _ in range(3):
            turnUp(d)
    elif t == 'E':
        break
    
print("%.2f"%best)
