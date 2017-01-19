import sys
L = int(input())

def recur(h,prev,sofar):
    for i in prev:
        if prev[i] == h:
            recur(i,prev,sofar+1)
    else:
        global best
        best = max(best,sofar)

for l in range(L):
    n = int(input())
    a = []
    for i in range(n):
        a.append(input().strip())
    last = 0
    best = 0
    for i in range(n-1,-1,-1):
        if a[i] == a[0]:
            last = i
            break
    prev = {a[0] : a[last+1], a[last+1] : a[last+1]}
    for i in range(1,n):
        if a[i] not in prev:
            prev[a[i]] = a[i-1]
    h = a[last+1]
    prev[h] = 0
    recur(h,prev,0)
    print(10 * (len(a) - 2 * best)) 
