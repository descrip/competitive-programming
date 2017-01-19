n = int(input())
a,b,c = [int(i) for i in input().split()]
dp = [0] + [-1e9] * 100005
for i in range(1,n+1):
    dp[i] = max(dp[i-a], dp[i-b], dp[i-c]) + 1
print(dp[n])
