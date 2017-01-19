a, b = [int(_) for _ in input().split()]
ans = 0 
for i in range(a, b+1):
    if i >= 0 and i**0.5 == int(i**0.5):
        ans += 1
print(ans)
