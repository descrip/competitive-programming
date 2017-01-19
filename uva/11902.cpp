#include <bits/stdc++.h>
using namespace std;

int t, n;
bool avis[101], vis[101];
vector<int> adj[101];

void dfs(int pos, int ign){
	if (pos == ign || vis[pos]) return;
	else{
		vis[pos] = true;
		for (int i : adj[pos])
			dfs(i,ign);
	}
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> t;
	for (int tc = 1; tc <= t; ++tc){
		fill_n(adj,101,vector<int>());
		fill(vis,vis+101,false);
		cin >> n;
		for (int y = 0; y < n; ++y) for (int x = 0; x < n; ++x){
			bool b; cin >> b;
			if (b) adj[y].push_back(x);
		}
		cout << "Case " << tc << ":\n";
		dfs(0,-1);
		copy(vis,vis+101,avis);
		for (int i = 0; i < n; ++i){
			fill(vis,vis+101,false);
			cout << '+' << string(2*n-1,'-') << "+\n";
			dfs(0,i);
			for (int j = 0; j < n; ++j)
				cout << '|' << (avis[j] && !vis[j] ? 'Y' : 'N');
			cout << "|\n";
		}
		cout << '+' << string(2*n-1,'-') << "+\n";
	}
return 0;}
