n = int(input())
a = [int(i) for i in list(input())]
best = None

def toInt(a,i):
    copy = [str(i) for i in a]
    return int(''.join(copy[i:]) + ''.join(copy[:i]))

for z in range(10):
    for j in range(len(a)):
        if a[j] == 9:
            a[j] = 0
        else:
            a[j] += 1
    
    for i in range(len(a)):
        if a[i] == 0:
            if best == None:
                best = toInt(a,i)
            else:
                best = min(best,toInt(a,i))

print(str(best).zfill(n))
