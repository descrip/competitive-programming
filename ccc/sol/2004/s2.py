n,k = [int(d) for d in input().split()]
worst = [0]*n
score = [0]*n
for r in range(k):
    points = [int(d) for d in input().split()]
    for i in range(n):
        score[i] += points[i]
    copy = sorted(list(set(score)),reverse=True)
    for i in range(n):
        worst[i] = max(worst[i],copy.index(score[i])+1)
best = max(score)
for i in range(n):
    if score[i] == best:
        print("Yodeller %i is the TopYodeller: score %i, worst rank %i"%(i+1,score[i],worst[i]))
