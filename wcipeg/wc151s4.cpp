#include <bits/stdc++.h>
using namespace std;

const int MAXN = 205;
int N, K, P[MAXN], F[MAXN], dp[MAXN][MAXN];
vector<int> adj[MAXN];

void recur(int pos){
	if (adj[pos].empty()){
		dp[pos][0] = 1;
		return;
	}
	for (int i = 0; i <= K; ++i){
		for (int j = 0; j <= i; ++j)
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; ++i){
		cin >> P[i] >> x >> F[i];
		adj[x].push_back(i);
	}
return 0;}

