// {{{ Headers 
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>//#include <cstdio>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std; typedef unsigned long ul; typedef long long ll; typedef unsigned long long ull; typedef long double ld; typedef pair<int,int> pii;
#define pb push_back
#define __ << ' ' <<
#define MOD 1000000007
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
// }}}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int exp, noob; cin >> exp >> noob;
	vector<vector<int>> dp (exp+1, vector<int> (noob+1,0));
	dp[2][1] = 1;
	dp[1][2] = 1;
	for (int e = 2; e <= exp; ++e){
		for (int n = 2; n <= noob; ++n){
			dp[e][n] = max(
					max(dp[e-1][n],dp[e][n-1]),
					max(dp[e-2][n-1]+1,dp[e-1][n-2]+1)
					);
		}
	}
	cout << dp[exp][noob] << '\n';
return 0;}
