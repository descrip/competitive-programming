import random, string
n = int(input())
q = int(input())
s = ""
for i in range(n):
    if (random.randint(0, 3) == 0):
        s += "G"
    else:
        s += random.choice(string.ascii_letters).upper()
print(s)
print(q)
for i in range(q):
    x = random.randint(0, len(s)-1)
    y = random.randint(0, len(s)-1)
    print(min(x,y), max(x,y))
