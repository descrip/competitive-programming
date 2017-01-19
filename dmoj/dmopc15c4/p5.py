l = [0] * 10;
n = int(input())
for i in range(0,n):
    s = str(i)
    for c in s:
        l[ord(c) - 48] += 1
print(l)
