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

struct edge{
	int dest, len, cost;
	edge(int a, int b, int c) : dest(a), len(b), cost(c) {}
};

vector<int> djik(int pos, const vector<vector<edge>> &adj){
	vector<int> ret (adj.size(),0xFFFFFFF);
	priority_queue<pii,vector<pii>,greater<pii>> q;
	q.push({0,pos});
	while (!q.empty()){
		auto curr = q.top(); q.pop();
		ret[curr.second] = min(ret[curr.second],curr.first);
		for (auto i : adj[curr.second])
			if (ret[i.dest] == 0xFFFFFFF)
				q.push({curr.first+i.len,i.dest});
	}
	return ret;
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n, m, a, b; cin >> n >> m >> a >> b;
	vector<vector<edge>> adj (n+1, vector<edge> ()), radj (n+1, vector<edge> ());
	for (int i = 0; i < m; ++i){
		int x, y, l, c; cin >> x >> y >> l >> c;
		adj[x].pb(edge(y,l,c));
		radj[y].pb(edge(x,l,c));
	}
	vector<int> dist = djik(a,adj), rdist = djik(b,radj);
	vector<pii> breaks;
	for (int i = 1; i < adj.size(); ++i)
		for (auto j : adj[i])
			if (dist[i] != 0xFFFFFFF && rdist[j.dest] != 0xFFFFFFF)
				breaks.pb({dist[i]+rdist[j.dest]+j.len, j.cost});
	sort(breaks.begin(),breaks.end());
	vector<int> ps (breaks.size());
	for (int i = 0; i < ps.size(); ++i)
		ps[i] = ps[i-1] + breaks[i].second;
	int q; cin >> q;
	if (ps.empty()){
		cout << 0 << '\n';
		return 0;
	}
	for (int i = 0; i < q; ++i){
		int d; cin >> d;
		cout << ps[upper_bound(breaks.begin(),breaks.end(),make_pair(d,0xFFFFFFF))-breaks.begin()-1] << '\n';
	}
return 0;}
