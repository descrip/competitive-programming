from random import randint, shuffle
a = list(range(1,5001))
shuffle(a)
a = a[:2000]
a.sort()
s = set([])
for i in range(2000):
    for j in range(i+1, 2000):
        s.add(a[i]-a[j])
print(len(s))
