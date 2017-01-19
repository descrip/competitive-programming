n = int(input())
l = []
for i in range(n):
    l.append(int(input()))
if max(l) > n:
    print("Yes")
else:
    print("No")
