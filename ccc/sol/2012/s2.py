s = input().strip()
s = [(int(s[i]),s[i+1]) for i in range(0,len(s),2)]

d = {"I":1,"V":5,"X":10,"L":50,"C":100,"D":500,"M":1000}
def val(a):
    return (a[0] * d[a[1]],a[1])

s = [val(i) for i in s]
a = 0
for i in range(len(s)-1):
    if d[s[i+1][1]] > d[s[i][1]]:
        a -= s[i][0]
    else:
        a += s[i][0]
a += s[-1][0]
print(a)
