#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> adj[23];
int vis[23];

bool recur(int a, int d){
	if (vis[a] != 0)
		return false;
	//cout << a << ' ' << d << '\n';
	vis[a] = d;
	for (int i = 0; i < adj[a].size(); ++i)
		if (vis[adj[a][i]] != 0){
			if (vis[a] - vis[adj[a][i]] == 5)
				return true;
		}
		else if (recur(adj[a][i], d+1))
			return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; ++i){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cout << (recur(1, 1) ? "YES\n" : "NO\n");
return 0;}

