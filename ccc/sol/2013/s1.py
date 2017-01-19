d = int(input())
while True:
    d += 1
    z = list(str(d))
    z.sort()
    if z == list(sorted(set(z))):
        print(d)
        break
