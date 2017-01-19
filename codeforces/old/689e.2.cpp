# include <bits/stdc++.h>
using namespace std;
# define fi cin
# define fo cout
# define x first
# define y second
const int nmax = 2e5 + 5;
const int mod = 1e9 + 7;
int pow(int a,int b,int mod)
{
    int ans = 1;
    while (b)
    {
        if (b&1) ans = (1ll * ans * a) % mod;
        a = (1ll * a * a) % mod;
        b /= 2;
    }
    return ans;
}
int f[nmax];//factorial
int c[nmax];//inverse of factorial
map < int , int > s;
int C(int n,int k) // combination
{
    int ans = (1ll * f[n] * c[k]) % mod;
    return (1ll * ans * c[n - k]) % mod;
}
main(void)
{
    int n,k;
    int ans = 0;
    ios_base :: sync_with_stdio(0);
    fi>>n>>k;assert(1 <= k && k <= n && n <= 2e5);
    f[0] = c[0] = 1;
    for (int i = 1;i <= n;++i) f[i] = (1ll * f[i-1] * i) % mod,c[i] = pow(f[i],mod-2,mod);

    for (int i = 1; i <= n; ++i)
      cout << f[i] << " \n"[i==n];
    for (int i = 1; i <= n; ++i)
      cout << c[i] << " \n"[i==n];

    for (int i = 1;i <= n;++i)
    {
        int a,b;
        fi>>a>>b;
        assert(-1e9 <= a && a <= b && b <= 1e9);
        ++s[a];--s[b+1];
    }
    int l = s.begin()->x;
    int sum = 0;
    for (auto it : s)
    {
        int dist = it.x - l;
        if (sum >= k) ans += (1ll * C(sum,k) * dist) % mod;
        ans = (ans >= mod ? ans - mod : ans);
        sum += it.y;
        l = it.x;
    }
    return fo << ans << '\n',0;
}
