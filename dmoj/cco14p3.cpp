#include <vector>
#include <iostream>
#include <queue>
using namespace std;

const int MOD = 1000000007;
int n, w, m;
vector<pair<int,bool>> adj[201];
vector<int> proc;
int numchi[201], par[201];
long long dp[201][201][2];

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> n >> w >> m;
	for (int i = 0; i < m; ++i){
		char c; int a, b; cin >> c >> a >> b;
		adj[a].push_back({b,c == 'A'});
		++numchi[a]; par[b] = a;
	}
	queue<int> q;
	for (int i = 1; i <= n; ++i){
		if (par[i] == 0){
			adj[0].push_back({i,false}); ++numchi[0];
		}
		if (numchi[i] == 0) q.push(i);
	}
	while (!q.empty()){
		proc.push_back(q.front());
		if (q.front() != 0 && --numchi[par[q.front()]] == 0)
			q.push(par[q.front()]);
		q.pop();
	}
	for (int node : proc){
		dp[node][0][0] = dp[node][1][1] = 1;
		for (auto child : adj[node]){
			for (int tot = w; tot >= 0; --tot){
				long long temp0 = 0, temp1 = 0;
				for (int sub = 0; sub <= tot; ++sub){
					temp0 += dp[node][tot-sub][0] * (dp[child.first][sub][0] + dp[child.first][sub][1]);
					temp1 += dp[node][tot-sub][1] * dp[child.first][sub][!child.second];
					temp0 %= MOD; temp1 %= MOD;
				}
				dp[node][tot][0] = temp0;
				dp[node][tot][1] = temp1;
			}
		}
	}
	cout << dp[0][w][0] << '\n';
return 0;}
