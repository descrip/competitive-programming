#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000021;
int n, m, s, t;
vector<pair<int,int>> adj[100001], radj[100001];
long long sdist[100001], tdist[100001], sways[100001], tways[100001];
vector<pair<pair<int,int>,int>> edges;

void djik(int u, vector<pair<int,int>> a[], long long d[], long long w[]){
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
	pq.push({0,u});
	fill_n(d,100001,1000000000000000000LL);
	d[u] = 0;
	w[u] = 1;
	while (!pq.empty()){
		int x = pq.top().second;
		long long y = pq.top().first;
		pq.pop();
		if (y != d[x])
			continue;
		for (auto p : a[x]){
			if (y+p.second < d[p.first]){
				d[p.first] = y+p.second;
				w[p.first] = w[x];
				pq.push({y+p.second,p.first});
			}
			else if (y+p.second == d[p.first])
				w[p.first] = (w[p.first] + w[x]) % MOD;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> s >> t;
	for (int i = 0; i < m; ++i){
		int x, y, z; cin >> x >> y >> z;
		adj[x].push_back({y,z});
		radj[y].push_back({x,z});
		edges.push_back({{x,y},z});
	}
	djik(s,adj,sdist,sways);
	djik(t,radj,tdist,tways);
	for (int i = 0; i < m; ++i){
		int x = edges[i].first.first,
			y = edges[i].first.second;
		long long z = edges[i].second;
		if (sdist[t] == sdist[x]+tdist[y]+z && (sways[x]*tways[y])%MOD == sways[t])
			cout << "YES\n";
		else if (sdist[x]+tdist[y]+z-sdist[t]+1 < z)
			cout << "CAN " << sdist[x]+tdist[y]+z-sdist[t]+1 << '\n';
		else
			cout << "NO\n";
	}
return 0;}
