n = 0
for i in range(100,1000):
    for j in range(100,1000):
        s = str(i*j)
        if s == s[::-1]:
            n = max(n,i*j)
print(n)
