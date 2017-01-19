'''
s = []
leng = 5
def recur(a):
    global leng
    if len(a) == leng:
        a.sort()
        if a not in s:
            s.append(a)
    else:
        for i in range(leng):
            recur(a+[chr(i+97)])
recur([])
print(len(s))
'''

def cross(a):
    s = []
    for i in range(4):
        for j in range(4):
            for k in range(4):
                for l in range(4):
                    z = [a[i],a[j],a[k],a[l]]
                    z.sort()
                    s.append(z)
    return s

het = ['a','b','c']
res = [['a','b','c','d']]
newres = []
for z in range(2):
    for i in range(len(res)):
        newres += cross(res[i])
    res = newres[::]
    newres = []

s = res[::]
s.sort()

g = [1]
inGroup = False
for i in range(1,len(s)):
    if inGroup:
        if s[i] == s[i-1]:
            g[-1] += 1
        else:
            g.append(1)
            inGroup = False
    else:
        if s[i] == s[i-1]:
            g[-1] += 1
            inGroup = True
        else:
            g.append(1)
g.sort()
print(g)
for i in g:
    print(i / sum(g))
