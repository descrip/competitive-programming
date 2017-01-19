def factor(n):
    d = 2
    f = [0] * 21
    while n > 1:
        while n % d == 0:
            n //= d
            f[d] += 1
        d += 1 
        if d ** 2 > n:
            f[n] += 1
            break
    return f 

a = [0] * 21
for i in range(1,21):
    l = factor(i)
    for j in range(len(l)):
        if a[j] < l[j]:
            a[j] = l[j]

z = 1
for i in range(1,21):
    z *= i ** a[i]

print(z)
