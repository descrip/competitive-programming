n = int(input())
s = [[chr(97+n-1)] * (2*n-1) for i in range(2*n-1)]
p,w = 1,2*n-3
for i in range(n-2,-1,-1):
    for y in range(w):
        for x in range(w):
            s[y+p][x+p] = chr(97+i)
    p += 1
    w -= 2
for i in s:
    print(''.join(i))
