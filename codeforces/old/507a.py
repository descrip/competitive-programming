n, k = [int(_) for _ in input().split()]
a = [int(_) for _ in input().split()]
d = []
while k > 0:
    z = a.index(min(a))
    if a[z] <= k:
        k -= a[z]
        d.append(z+1)
        a[z] = 9999
    else:
        break
d.sort()
print(len(d))
print(" ".join([str(_) for _ in d]))
