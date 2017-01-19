N = int(input())
a = [0] * 1001
for i in range(N):
    R = int(input())
    a[R] += 1
m = max(a)
best = []
for i in range(len(a)):
    if a[i] == m:
        best.append(i)
        a[i] = 0
sm = max(a)
sbest = []
for i in range(len(a)):
    if a[i] == sm:
        sbest.append(i)
if len(best) == 1:
    print(max(max(best) - min(sbest),max(sbest) - min(best)))
else:
    print(max(best) - min(best))
