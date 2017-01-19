#brute force, had a cool solution but it didnt work out ):

ans = 0
for i in range(1,1000000):
    s = str(i)
    s2 = bin(i)[2:]
    if s == s[::-1] and s2 == s2[::-1]:
        ans += i
print(ans)
