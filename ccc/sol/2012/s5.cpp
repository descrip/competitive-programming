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

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int r, c; cin >> r >> c;
	vector<vector<ll>> dp (r+2, vector<ll> (c+2, 0));
	int k; cin >> k;
	for (int i = 0; i < k; ++i){
		int a, b; cin >> a >> b;
		dp[a][b] = -1;
	}
	dp[1][1] = 1;
	for (int y = 1; y <= r; ++y)
		for (int x = 1; x <= c; ++x){
			if (dp[y][x] == -1) continue;
			if (dp[y-1][x] != -1) dp[y][x] += dp[y-1][x];
			if (dp[y][x-1] != -1) dp[y][x] += dp[y][x-1];
		}
	cout << dp[r][c] << '\n';
return 0;}
