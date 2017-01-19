n = int(input())
a = [int(i) for i in input().split()]

def diff(a):
    best = 0
    for i in range(1,len(a)):
        best = max(best,a[i] - a[i-1])
    return best

best = 9999
for i in range(1,n-1):
    best = min(best,diff(a[:i]+a[i+1:]))

print(best)
