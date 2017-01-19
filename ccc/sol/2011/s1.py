n = int(input())
s = ""
for _ in range(n):
    s += input().strip().lower()
x = s.count('s')
y = s.count('t')
if x >= y:
    print("French")
else:
    print("English")
