n = 600851475143 
d = 2
best = 2
while n > 1:
    while n % d == 0:
        n /= d
        best = max(best,d)
    d += 1
    if d ** 2 > n:
        best = max(best,n)
        break
print(int(best))
