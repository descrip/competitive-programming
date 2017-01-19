A = int(input())
B = int(input())
N = int(input())
H = []

for i in range(N):
    H.append(int(input()))

H += [0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000]
H.sort()

dp = [0 for i in range(7001)]
dp[0] = 1

for i in range(1, len(H)):
    for j in range(i):
        if A <= H[i] - H[j] <= B:
            dp[i] += dp[j]

print(dp[len(H)-1])
