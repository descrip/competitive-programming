#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<int>> adj (n+1);
	for (int i = 0; i < m; ++i){
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	//Case 1: No edges.
	if (m == 0){
		cout << "3 " << (long long) n * (n-1) * (n-2) / 6 << '\n';
		return 0;
	}
	//Case 2: All components have <2 verticies.
	for (int i = 1; i <= n; ++i){
		if (adj[i].size() > 1) break;
		else if (i == n){
			cout << "2 " << (long long) m * (n-2) << '\n';
			return 0;
		}
	}
	queue<int> q;
	vector<int> vis (n+1);	//0: not visited, 1: red, 2: blue
	bool bipar = true;
	long long ans = 0;
	for (int i = 1; i <= n; ++i){
		if (vis[i] == 0){
			long long red = 0, blue = 0;
			q.push(i);
			while (!q.empty()){
				int a = q.front();
				q.pop();
				if (vis[a] != 0) continue;
				int ared = 0, ablue = 0;
				for (int j : adj[a]){
					if (vis[j] == 1) ++ared;
					else if (vis[j] == 2) ++ablue;
					else q.push(j);
				}
				if (ared >= 0 && ablue == 0){
					vis[a] = 2;
					++blue;
				}
				else if (ared == 0 && ablue >= 0){
					vis[a] = 1;
					++red;
				}
				else{
					bipar = false;
					break;
				}
			}
			//Case 3: Not bipartite graph, already has odd cycle.
			if (!bipar){
				cout << "0 1\n";
				return 0;
			}
			//Case 4: Bipartite graph.
			else
				ans += red*(red-1)/2 + blue*(blue-1)/2;
		}
	}
	cout << "1 " << ans << '\n';
return 0;}
