s = [input().strip() for _ in range(2)]
d = {}
for i in range(len(s[0])):
    if s[1][i] not in d:
        d[s[1][i]] = s[0][i]
a = " "
for i in range(26):
    a += chr(65+i)
if len(d) == 26:
    for i in a:
        if i not in d:
            for j in a:
                if j not in d.values():
                    d[i] = j
                    break
x = input().strip()
a = ""
for i in x:
    if i in d:
        a += d[i]
    else:
        a += '.'
print(a)
