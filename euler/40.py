#more scummy python solutions

s = ""
curr = 1
while len(s) < 1000000:
    s += str(curr)
    curr += 1
ans = 1
for i in range(6):
    ans *= int(s[10**i-1]);
print(ans)
