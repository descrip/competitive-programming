#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M, K; cin >> N >> M >> K;
	static bool exit[100000];
	static vector<pair<int, long long>> adj[100000];
	for (int i = 0; i < M; ++i){
		int a, b;
		long long c;
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	for (int i = 0; i < K; ++i){
		int a; cin >> a;
		exit[a] = true;
	}
return 0;}

