def isPalin(n):
    return str(n) == str(n)[::-1]

def oper(n):
    return n + int(str(n)[::-1])

ans = 0

for i in range(1,10000):
    n = i
    for j in range(50):
        n = oper(n)
        if isPalin(n):
            break
        elif j == 49:
            ans += 1

print(ans)
