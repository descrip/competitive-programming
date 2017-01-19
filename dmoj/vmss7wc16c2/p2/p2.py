import sys
s = sys.stdin.readline()
l = [0]
for c in s:
    if c == 'G':
        l.append(l[-1]+1)
    else:
        l.append(l[-1])
l = l[1:]
q = int(sys.stdin.readline())
for i in range(q):
    x, y = [int(_) for _ in sys.stdin.readline().split()]
    if x == 0:
        print(l[y])
    else:
        print(l[y]-l[x-1])
