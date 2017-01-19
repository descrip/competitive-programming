import random
an = 1000000
n = random.randint(int(an-an/10),int(an+an/10))
n = min(n, an)
n = an
s = ""
for i in range(n):
    x = str(random.randint(0,9))
    if x == "0" and s == "":
        continue
    s += x
print(s)
