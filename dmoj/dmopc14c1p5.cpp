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
	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	vector<vector<int>> v (r+2,vector<int>(c+2));
	for (int i = 1; i <= r; ++i){
		for (int j = 1; j <= c; ++j){
			char a; cin >> a;
			v[i][j] = (a == 'X' ? 0 : 1);
		}
	}
	int t; cin >> t;
	for (int i = 0; i < t; ++i){
		int x, y; cin >> x >> y;
		v[x+1][y+1] = 2;
	}
	int fast = 0xFFFFFFF;
	vector<vector<int>> dp (r+2,vector<int>(c+2,0xFFFFFFF));
	queue<pii> q;
	dp[x1+1][y1+1] = 0;
	q.push({x1+1,y1+1});
	while (!q.empty()){
		int x = q.front().first, y = q.front().second;
		q.pop();
		if (v[x][y] == 0)
			continue;
		else if (v[x][y] >= 1){
			if (v[x][y] == 2)
				fast = min(fast,dp[x][y]);
			if (dp[x-1][y] > dp[x][y]+1){
				dp[x-1][y] = dp[x][y]+1;
				q.push({x-1,y});
			}
			if (dp[x+1][y] > dp[x][y]+1){
				dp[x+1][y] = dp[x][y]+1;
				q.push({x+1,y});
			}
			if (dp[x][y-1] > dp[x][y]+1){
				dp[x][y-1] = dp[x][y]+1;
				q.push({x,y-1});
			}
			if (dp[x][y+1] > dp[x][y]+1){
				dp[x][y+1] = dp[x][y]+1;
				q.push({x,y+1});
			}
		}
	}
	cout << dp[x2+1][y2+1]-fast << endl;
return 0;}
