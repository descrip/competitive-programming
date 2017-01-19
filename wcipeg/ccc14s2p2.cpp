#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;
#define fi first
#define se second

const int MAX = 100001;
int N, M, A, B, Q, fromA[MAX], fromB[MAX];
vector<vector<pair<int,pair<int,int>>>> adj, radj;
vector<pair<int,int>> ans;

void djik(int s, int w[MAX], vector<vector<pair<int,pair<int,int>>>> a){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q; q.push({0,s});
	while (!q.empty()){
		auto p = q.top(); q.pop();
		if (w[p.se] != -1) continue;
		w[p.se] = p.fi;
		for (int i = 0; i < a[p.se].size(); ++i)
			q.push({p.fi+a[p.se][i].se.fi,a[p.se][i].fi});
	}
}

int main(){
	cin >> N >> M >> A >> B;
	adj.resize(MAX); radj.resize(MAX);
	for (int i = 0; i < M; ++i){
		int s, t, u, v; cin >> s >> t >> u >> v;
		adj[s].push_back({t,{u,v}});
		radj[t].push_back({s,{u,v}});
	}
	fill(fromA,fromA+MAX,-1);
	fill(fromB,fromB+MAX,-1);
	djik(A,fromA,adj); djik(B,fromB,radj);
	for (int i = 1; i <= N; ++i)
		if (fromA[i] != -1)
			for (int j = 0; j < adj[i].size(); ++j)
				if (fromB[adj[i][j].fi] != -1)
					ans.push_back({fromA[i]+fromB[adj[i][j].fi]+adj[i][j].se.fi,adj[i][j].se.se});
	sort(ans.begin(),ans.end());
	for (int i = 1; i < ans.size(); ++i)
		ans[i].se += ans[i-1].se;
	cin >> Q;
	for (int i = 0; i < Q; ++i){
		int a; cin >> a;
		auto it = lower_bound(ans.begin(),ans.end(),make_pair(a+1,0));
		if (it == ans.begin()){
			cout << "0\n"; continue;
		}
		--it;
		cout << it->se << '\n';
	}
}
