n = int(input())
d = [int(_) for _ in input().split()]
d.sort()
d.reverse()
con = [d[0]]
for i in range(1,len(d)):
    for j in range(len(con)):
        if con[j] > d[i]:
            con[j] = d[i]
            break
    else:
        con.append(d[i])
print(len(con))
