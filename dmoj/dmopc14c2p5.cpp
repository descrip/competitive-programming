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
	int n, m; scan(n); scan(m);
	vector<vector<int>> go (n+1,vector<int>()), ungo (n+1,vector<int>());
	vector<int> ungocnt (n+1);
	for (int i = 0; i < m; ++i){
		int a, b; scan(a); scan(b);
		go[a].pb(b);
		ungo[b].pb(a);
	}
	vector<int> ends;
	for (int i = 1; i <= n; ++i)
		if (go[i].size() == 0)
			ends.pb(i);
	vector<ld> dp (n+1);
	queue<int> q; q.push(1);
	dp[1] = 1.0;
	vector<bool> vis (n+1);
	while (!q.empty()){
		int curr = q.front();
		q.pop();
		if (vis[curr]) continue;
		if (ungocnt[curr] != ungo[curr].size()){
			q.push(curr);
			continue;
		}
		for (int i : go[curr]){
			dp[i] += dp[curr] / go[curr].size();
			++ungocnt[i];
			q.push(i);
		}
		vis[curr] = true;
	}
	cout.precision(11);
	for (int i : ends)
		cout << fixed << dp[i] << '\n';
return 0;}
