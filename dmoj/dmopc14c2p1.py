d = int(input())
for i in range(d):
    n = int(input())
    s = 0
    for j in range(n):
        s += int(input())
    if s == 0:
        print("Weekend")
    else:
        print("Day "+str(i+1)+":",s)
