#include <bits/stdc++.h>
using namespace std;

int N, D, dp[305][700];
vector<int> adj[305];
bool col[305];

//D = W - B
/*
 *
 */

int wow(bool what){
	return (what ? 1 : -1);
}

void recur(int pos){
	dp[pos][0+350] = 1;
	for (int v : adj[pos])
		recur(v);
	if (adj[pos].empty())
		dp[pos][wow(col[pos]) + 350] = 0;
	else if (adj[pos].size() == 1)
		for (int i = -N; i <= N; ++i)
			dp[pos][i + wow(col[pos]) + 350] = min(dp[pos][i + wow(col[pos]) + 350], dp[adj[pos][0]][i + 350]);
	else if (adj[pos].size() == 2){
		for (int i = -N; i <= N; ++i)
			for (int j = -N; j <= N; ++j)
				dp[pos][i + wow(col[pos]) + 350] = min(dp[pos][i + wow(col[pos]) + 350], dp[adj[pos][0]][j+350] + dp[adj[pos][1]][i-j+350]);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> D;
	fill_n(dp[0], 305*700, 0xfffffff);
	for (int i = 0; i < N; ++i){
		int id, c, C; cin >> id >> c >> C;
		col[id] = c;
		for (int j = 0; j < C; ++j){
			int x; cin >> x;
			adj[id].push_back(x);
		}
	}
	recur(0);
	if (dp[0][D+350] >= 0xfffffff)
		cout << "-1\n";
	else
		cout << dp[0][D+350] << '\n';
return 0;}

