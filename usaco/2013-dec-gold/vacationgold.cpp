#include <bits/stdc++.h>
using namespace std;

const int NMAX = 2e4+5, KMAX = 200;
int n, m, k, q, dist[KMAX][NMAX], rdist[KMAX][NMAX], hubs[KMAX];
vector<pair<int,int>> adj[NMAX], radj[NMAX];
bool vis[NMAX];

void djik(int v, int r, vector<pair<int,int>> a[NMAX], int d[KMAX][NMAX]){
	fill(vis, vis+NMAX, false);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0, v});
	while (!pq.empty()){
		int x = pq.top().second, y = pq.top().first;
		pq.pop();
		if (vis[x])
			continue;
		vis[x] = true;
		d[r][x] = y;
		for (auto p : a[x])
			if (!vis[p.first])
				pq.push({y + p.second, p.first});
	}
}

int main(){
	//ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream fin ("vacationgold.in");
	ofstream fout ("vacationgold.out");
	fin >> n >> m >> k >> q;
	for (int i = 0; i < m; ++i){
		int a, b, d; fin >> a >> b >> d;
		adj[a].push_back({b, d});
		radj[b].push_back({a, d});
	}
	for (int i = 0; i < KMAX; ++i)
		for (int j = 0; j < NMAX; ++j)
			dist[i][j] = rdist[i][j] = -1;
	for (int i = 0; i < k; ++i){
		fin >> hubs[i];
		djik(hubs[i], i, adj, dist);
		djik(hubs[i], i, radj, rdist);
	}
	int num = 0;
	long long ans = 0;
	for (int i = 0; i < q; ++i){
		int a, b, d = 0xfffffff; fin >> a >> b;
		for (int j = 0; j < k; ++j)
			if (rdist[j][a] != -1 && dist[j][b] != -1)
				d = min(d, rdist[j][a] + dist[j][b]);
		if (d != 0xfffffff){
			++num;
			ans += d;
		}
	}
	fout << num << '\n' << ans << '\n';
	fin.close(); fout.close();
return 0;}
