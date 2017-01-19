rx,ry,jx,jy = [int(_) for _ in input().split()]
n = int(input())

def cross(x1,y1,x2,y2):
    return y2*x1 - x2*y1

def direction(x1,y1,x2,y2,x3,y3):
    return cross(x2-x1,y2-y1,x3-x1,y3-y1) 
    
def onseg(x1,y1,x2,y2,x3,y3):
    if min(x1,x2) <= x3 <= max(x1,x2) and min(y1,y2) <= y3 <= max(y1,y2):
        return True
    else:
        return False

def intersect(x1,y1,x2,y2,x3,y3,x4,y4):
    d1 = direction(x3,y3,x4,y4,x1,y1)
    d2 = direction(x3,y3,x4,y4,x2,y2)
    d3 = direction(x1,y1,x2,y2,x3,y3)
    d4 = direction(x1,y1,x2,y2,x4,y4)
    if ((d1 > 0 and d2 < 0) or (d1 < 0 and d2 > 0)) and ((d3 > 0 and d4 < 0) or (d3 < 0 and d4 > 0)):
        return True
    elif (d1 == 0 and onseg(x3,y3,x4,y4,x1,y1)):
        return True
    elif (d2 == 0 and onseg(x3,y3,x4,y4,x2,y2)):
        return True
    elif (d3 == 0 and onseg(x1,y1,x2,y2,x3,y3)):
        return True
    elif (d4 == 0 and onseg(x1,y1,x2,y2,x4,y4)):
        return True
    else:
        return False

cnt = 0
for _ in range(n):
    s = [int(_) for _ in input().split()]
    v = s.pop(0)
    s.extend(s[:2])
    for i in range(0,len(s) - 2,2):
        ax,ay,bx,by = s[i:i+4]
        if intersect(rx,ry,jx,jy,ax,ay,bx,by):
            cnt += 1
            break

print(cnt)
