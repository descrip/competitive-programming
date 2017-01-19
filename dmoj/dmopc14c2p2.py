n = int(input())
s = input().strip().split('X')
for i in range(len(s)-1,-1,-1):
    if s[i] == '':
        del s[i]
print(len(s))
for i in s:
    print(i)
