import sys

s = list(input().strip())
t = list(input().strip())

if len(t) > len(s):
    s,t = t,s

def canswap(s,t):
    if len(s) != len(t):
        return False
    for i in range(len(t)):
        for j in range(i+1,len(t)):
            t[i], t[j] = t[j], t[i]
            print(i,j,t)
            if s == t:
                return True
            t[i], t[j] = t[j], t[i]
    return False

for i in range(len(s)):
    r = s[:i] + s[i+1:]
    if canswap(r,t):
        print("both")
        sys.exit(0)

if t in s:
    print("automaton")
    sys.exit(0)

if canswap(s,t):
    print("array")
    sys.exit(0)

print("need tree")
