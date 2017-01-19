p = [input(),input()]
poss = [[] for i in range(5)]
for i in range(5):
    for j in range(2):
        for k in range(2):
            z = (p[0][2*i+j],p[1][2*i+k])
            if z[0].islower() and z[1].islower():
                poss[i].append(z[0])
            else:
                poss[i].append(z[0].upper())
x = int(input())
for i in range(x):
    s = input()
    for j in range(5):
        if s[j] not in poss[j]:
            print("Not their baby!")
            break
    else:
        print("Possible baby.")
