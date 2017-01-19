#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> adj[1000000];
bool vis[1000000];

pair<int, int> recur(int len, int pos){
	if (vis[pos])
		return {0, 0};
	vis[pos] = true;
	pair<int, int> ans = {0, 0};
	for (int i : adj[pos]){
		pair<int, int> p = recur(len+1, pos);
		++p.first;
		ans = max(ans, p);
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; ++i){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	pair<int, int> p = recur(0, 0);
	cout << recur(0, p.second).first << '\n';
return 0;}

