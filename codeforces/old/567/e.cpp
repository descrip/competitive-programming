#include <bits/stdc++.h>
using namespace std;

int n, m, s, t;
vector<pair<int,pair<int,int>>> adj[100001], radj[100001];
vector<pair<int,pair<int,int>>> ord;
long long sdist[100001], tdist[100001];
vector<set<int>> paths;
set<int> rev, no;
set<pair<int,int>> dup;

void djik(int st, vector<pair<int,pair<int,int>>> v[], long long w[]){
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
	pq.push({0,st});
	while (!pq.empty()){
		int x = pq.top().second;
		long long y = pq.top().first;
		pq.pop();
		if (w[x] != 0)
			continue;
		w[x] = y;
		for (auto u : v[x])
			pq.push({y+u.second.second, u.second.first});
	}
}

void bfs(int u, long long dist){
	if (u == t && dist == sdist[t]){
		paths.push_back(rev);
		return;
	}
	if (dist > sdist[t])
		return;
	for (auto p : adj[u]){
		rev.insert(p.first);
		bfs(p.second.first,dist+p.second.second);
		rev.erase(p.first);
	}
}

int main(){
	//ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> s >> t;
	for (int i = 0; i < m; ++i){
		int x, y, z; cin >> x >> y >> z;
		ord.push_back({x,{y,z}});
		if (dup.count(make_pair(x,y)) != 0){
			for (int j = 0; j < adj[i].size(); ++j)
				if (adj[i][j].second.first == y){
					if (adj[i][j].second.second > z){
						adj[i][j].second.second = z;
						no.insert(adj[i][j].first);
						adj[i][j].first = i;
						for (int k = 0; k < radj[y].size(); ++k)
							if (radj[y][k].second.first == x){
								radj[y][k].second.second = z;
								radj[y][k].first = i;
								break;
							}
						break;
					}
					else if (adj[i][j].second.second == z){
						adj[x].push_back({i,{y,z}});
						radj[y].push_back({i,{x,z}});
						break;
					}
					else{
						no.insert(i);
						break;
					}
				}
			continue;
		}
		dup.insert({x,y});
		adj[x].push_back({i,{y,z}});
		radj[y].push_back({i,{x,z}});
	}
	djik(s,adj,sdist);
	djik(t,radj,tdist);
	bfs(s,0);
	for (int i = 0; i < m; ++i){
		if (no.count(i) == 1){
			cout << "NO\n";
			continue;
		}
		long long x = ord[i].first,
			y = ord[i].second.first,
			z = ord[i].second.second;
		bool yes = true;
		for (set<int> s : paths)
			if (s.count(i) == 0)
				yes = false;
		if (yes)
			cout << "YES\n";
		else{
			if (sdist[x]+tdist[y]+z-sdist[t]+1 >= z)
				cout << "NO\n";
			else
				cout << "CAN " << sdist[x]+tdist[y]+z-sdist[t]+1 << '\n';
		}
	}
return 0;}
