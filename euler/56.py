def digSum(n):
    return sum([int(_) for _ in list(str(n))])

ans = 0
for a in range(1, 100):
    for b in range(1, 100):
        ans = max(ans, digSum(a ** b))

print(ans)
