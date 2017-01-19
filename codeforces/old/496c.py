import sys

n, m = [int(i) for i in input().split()]
a = [[0] * n for i in range(m)]
for i in range(n):
    temp = input()
    for j in range(m):
        a[j][i] = temp[j]
        
c = 0
while len(a) > 0:
    for i in range(1,n):
        if a[0][i] == a[0][i-1]:
            j = 1
            while j < len(a):
                print(a[j])
                if a[j][i] > a[j][i-1]:
                    break
                elif a[j][i] < a[j][i-1]:
                    del a[j]
                    j -= 1
                    #print(j)
                j += 1
            else:
                for k in range(len(a)):
                    if a[k][i] != a[k][i - 1]:
                        print(m)
                        sys.exit(0)
                    else:
                        print(i,k,a[k])
        elif a[0][i] < a[0][i-1]:
            del a[0]
            break
    else:
        break
    continue

print(c)
