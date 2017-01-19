n = 5
vis = [[0] * (2**n) for i in range(2**n)]
for i in range((4**n)//3):
    try:
        x1,y1,x2,y2,x3,y3 = [int(_) for _ in input().split()]
        print(x1,y1,x2,y2,x3,y3)
        vis[y1][x1] += 1
        vis[y2][x2] += 1
        vis[y3][x3] += 1
    except:
        continue
for y in range(2**n):
    print(vis[y])
