#because splitting is hard in c++

s = input().split('","')
s[0] = s[0][1:]
s[-1] = s[-1][:-1]
s.sort()

ans = 0
for i in range(len(s)):
    curr = 0
    for c in s[i]:
        curr += ord(c) - 65 + 1
    ans += curr * (i+1)

print(ans)
