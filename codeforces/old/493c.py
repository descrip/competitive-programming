n = int(input())
a = [int(_) for _ in input().split()]
m = int(input())
b = [int(_) for _ in input().split()]

MAX = max(max(a),max(b))

lo = -1
hi = MAX

def points(a,b,d):
    ap = 0
    bp = 0
    for i in a:
        if i > d:
            ap += 3
        else:
            ap += 2
    for i in b:
        if i > d:
            bp += 3
        else:
            bp += 2
    return (ap,bp)

mid = (lo + hi) // 2
bestap, bestbp = points(a,b,mid)

ap1,bp1,ap2,bp2 = bestap,bestbp,bestap,bestbp

while hi > lo + 1:
    print(lo,hi)
    if ap1 - bp1 > bestap - bestbp:
        bestap = ap1
        bestbp = bp1
    elif ap2 - bp2 > bestap - bestbp:
        bestap = ap2
        bestbp = bp2
    ap1,bp1 = points(a,b,(lo + mid)//2)
    ap2,bp2 = points(a,b,(mid+hi)//2)
    if ap1 - bp1 > ap2 - bp2:
        hi = mid
    elif ap1 - bp1 < ap2 - bp2:
        lo = mid
        print(2)
    else:
        break
