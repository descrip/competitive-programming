a, b = [int(n) for n in input().split()]
c = a - b
x = 1
z = 0

if a == b:
    print("infinity")
else:
    while x ** 2 <= c:
        if c % x == 0:
            if x > b:
                z += 1
            if x ** 2 != c and c / x > b:
                z += 1
        x += 1
    print(z)
