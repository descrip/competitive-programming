n = [int(_) for _ in list(input())]
best = -1
for i in range(len(n)-1):
    if n[i] % 2 == 0:
        n[i], n[-1] = n[-1], n[i]
        best = max(best,n)
        n[i], n[-1] = n[-1], n[i]
print(''.join([str(_) for _ in best]))
