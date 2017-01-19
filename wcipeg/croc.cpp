#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M, K; cin >> N >> M >> K;
	static vector<int> adj[100000];
	for (int i = 0; i < M; ++i){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
return 0;}

