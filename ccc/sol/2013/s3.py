t = int(input())
g = int(input())
pts = [0] * 4
games = []
for i in range(4):
    for j in range(i+1,4):
        games.append((i,j))
for i in range(g):
    a, b, sa, sb = [int(_) for _ in input().split()]
    a -= 1
    b -= 1
    games.remove((a,b))
    if sa == sb:
        pts[a] += 1
        pts[b] += 1
    elif sa > sb:
        pts[a] += 3
    else:
        pts[b] += 3
q, newq = [pts], []
for i in games:
    for j in q:
        j[i[0]] += 3
        newq.append(j[::])
        j[i[0]] -= 3
        j[i[1]] += 3
        newq.append(j[::])
        j[i[0]] += 1
        j[i[1]] -= 2
        newq.append(j[::])
    q = newq[::]
    newq = []
cnt = 0
for i in q:
    if i[t-1] == max(i) and i.count(max(i)) == 1:
        cnt += 1
print(cnt)
