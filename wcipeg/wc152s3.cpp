#include <bits/stdc++.h>
using namespace std;

int N, M, mark[45679];
vector<int> adj[45679];
bool nope = false;

pair<int, int> recur(int pos, bool coin){
	if (mark[pos] != 0)
		return {0, 0};
	mark[pos] = coin + 1;
	pair<int, int> ret;
	if (coin)
		ret = {1, 0};
	else 
		ret = {0, 1};
	for (int v : adj[pos]){
		if (mark[v] == 0){
			pair<int, int> tmp = recur(v, !coin);
			ret.first += tmp.first;
			ret.second += tmp.second;
		}
		else if (mark[v] == coin+1)
			nope = true;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; ++i){
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int ans = 0;
	for (int i = 1; i <= N; ++i){
		if (mark[i] != 0)
			continue;
		nope = false;
		pair<int, int> tmp = recur(i, true);
		//cout << i << ' ' << tmp.first << ' ' << tmp.second << ' ' << nope << '\n';
		if (!nope)
			ans += tmp.first * tmp.first + tmp.second * tmp.second;
		else
			ans += (tmp.first + tmp.second) * (tmp.first + tmp.second);
	}
	cout << fixed << setprecision(9) << ans / (double)(N*N) << '\n';
return 0;}

