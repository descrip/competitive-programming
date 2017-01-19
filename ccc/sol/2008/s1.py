best = 200
name = ""
while 1:
    s, t = input().split()
    t = int(t)
    if t < best:
        best = t
        name = s
    if s == "Waterloo":
        break
print(name)
