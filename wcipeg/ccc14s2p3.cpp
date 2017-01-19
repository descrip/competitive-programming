#include <vector>
#include <queue>
#include <iostream>
using namespace std;

const int MOD = 1000000007;
int N, W, M, deg[201], par[201];
vector<int> topo;
vector<pair<int,bool>> adj[201];
long long dp[201][201][2];
queue<int> q;

int main(){
	cin >> N >> W >> M;
	for (int i = 0; i < M; ++i){
		char c; int a, b; cin >> c >> a >> b;
		adj[a].push_back({b,c == 'A'});
		++deg[a]; par[b] = a;
	}
	for (int i = 1; i <= N; ++i){
		if (par[i] == 0){
			adj[0].push_back({i,false});
			++deg[0];
		}
		if (deg[i] == 0) q.push(i);
	}
	while (!q.empty()){
		topo.push_back(q.front());
		if (q.front() != 0 && --deg[par[q.front()]] == 0)
			q.push(par[q.front()]);
		q.pop();
	}
	for (int n : topo){
		dp[n][0][0] = dp[n][1][1] = 1;
		for (auto c : adj[n]){
			for (int t = W; t >= 0; --t){
				long long t0 = 0, t1 = 0;
				for (int s = 0; s <= t; ++s){
					t0 += dp[n][t-s][0] * 
						(dp[c.first][s][1] + dp[c.first][s][0]);
					t1 += dp[n][t-s][1]
						* dp[c.first][s][!c.second];
					t0 %= MOD; t1 %= MOD;
				}
				dp[n][t][0] = t0;
				dp[n][t][1] = t1;
			}
		}
	}
	cout << dp[0][W][0] << '\n';
}
