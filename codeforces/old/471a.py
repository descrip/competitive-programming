import sys
a = [int(_) for _ in input().split()]
a.sort()
for i in range(len(a)):
    if a.count(a[i]) >= 4:
        for j in range(4):
            del a[i]
        break
else:
    print("Alien")
    sys.exit(0)
if a[0] == a[1]:
    print("Elephant")
else:
    print("Bear")
