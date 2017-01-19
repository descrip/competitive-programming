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
	int n, m; cin >> n >> m;
	priority_queue<pii,vector<pii>,greater<pii>> q;
	vector<bool> vis (10000);
	q.push({0,n});
	while (!q.empty()){
		auto curr = q.top();
		q.pop();
		if (curr.second == m){
			cout << curr.first << '\n';
			return 0;
		}
		if (!(1 <= curr.second && curr.second <= 10000) || vis[curr.second]) continue;
		vis[curr.second] = true;
		q.push({curr.first+1,curr.second-1});
		q.push({curr.first+1,curr.second*2});
	}
return 0;}
