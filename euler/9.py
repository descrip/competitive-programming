best = 0
for i in range(1,1000-1):
    for j in range(1,1000-i+1):
        if i ** 2 + j ** 2 == (1000 - i - j) ** 2:
            best = max(best,i * j * (1000 - i - j))
print(best)
