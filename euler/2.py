a = [1,2]
s = 0
while True:
    a.append(a[-1]+a[-2])
    if a[-1] < 4000000:
        if a[-1] % 2 == 0:
            s += a[-1]
    else:
        break
print(s+2)
