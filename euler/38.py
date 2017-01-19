ans = ""
for i in range(1, 100000):
    for j in range(2, 10):
        curr = ""
        for k in range(1, j+1):
            curr += str(i * k)
        s = list(curr)
        s.sort()
        if ''.join(s) == "123456789":
            print(i, j)
            ans = max(ans, curr)
print(ans)
