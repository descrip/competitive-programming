digits = [
[1,1,1,0,1,1,1],
[0,0,0,0,0,1,1],
[0,1,1,1,1,1,0],
[0,0,1,1,1,1,1],
[1,0,0,1,0,1,1],
[1,0,1,1,1,0,1],
[1,1,1,1,1,0,1],
[0,0,1,0,0,1,1],
[1,1,1,1,1,1,1],
[1,0,1,1,1,1,1]
]

def broke(n):
    poss = 0
    for i in digits:
        for j in range(len(i)):
            if i[j] == 0 and digits[n][j] == 1:
                break
        else:
            poss += 1
    return poss

n = int(input())
print(broke(n//10) * broke(n%10))
