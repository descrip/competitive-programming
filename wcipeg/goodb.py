import math
mod = 10**9+7
n, w, t, r = [int(_) for _ in input().split()]
w, t, r = sorted([w,t,r])
ans = 1
for i in range(w+1,n+1):
    ans *= i
ans = ans // (math.factorial(t) * math.factorial(r))
print(ans % mod)
