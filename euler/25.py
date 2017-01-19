a,b = 1,1
c = 2
while len(str(b)) < 1000:
    c += 1
    a,b = b,a+b
print(c)
