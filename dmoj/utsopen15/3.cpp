// {{{ Headers 
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>//#include <cstdio>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std; typedef long long ll; typedef unsigned long long ull; typedef long double ld; typedef pair<int,int> pii;
#define pb push_back
#define __ << ' ' <<
#define MOD 1000000007
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
// }}}

typedef unsigned long ul;
int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	if (m == 1)
		cout << 1 << endl;
	else if (m == 2){
		vector<ul> dp (n);
		dp[0] = dp[1] = dp[2] = 1;
		for (int i = 3; i < n; ++i){
			dp[i] = dp[i-1] + dp[i-3];
			dp[i] %= MOD;
		}
		cout << dp[n-1] << '\n';
	}
	else if (m == 3){
		vector<ull> a(n+1), b(n+1), c1(n+1), c2(n+1), d(n+1);
		for (int i = 1; i <= n; ++i){
			b[i] = a[max(0,i-2)] + c2[max(0,i-3)] + d[i-1] + d[max(0,i-3)];
			b[i] %= MOD;

			c2[i] = a[i-1] + a[max(0,i-2)] + c2[max(0,i-3)] + d[i-1] + d[max(0,i-3)];
			c2[i] %= MOD;

			c1[i] = a[max(i-2,0)] + c2[i];
			c1[i] %= MOD;

			a[i] = a[i-1] + b[max(0,i-2)] + c1[max(0,i-3)];
			a[i] %= MOD;
			a[1] = 1;

			d[i] = a[i] + b[i-1];
			d[i] %= MOD;
		}
		cout << a[n] << '\n';
	}
return 0;}
