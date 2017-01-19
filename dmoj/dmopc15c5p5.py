from random import randint, shuffle
n = int(input())
print(n)
s = "0 "
for i in range(2,n+1):
    s += str(randint(1, i-1)) + " "
print(s)
l = list(range(1,n+1))
shuffle(l)
print(" ".join([str(_) for _ in l]))
