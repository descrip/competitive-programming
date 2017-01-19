#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	static vector<int> adj[100001];
	static long long len[100001], cnt[100001];
	for (int i = 0; i < m; ++i){
		int a, b; cin >> a >> b;
		--a; --b;
		++cnt[a]; ++cnt[b];
		if (a > b)
			swap(a, b);
		adj[b].push_back(a);
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i){
		if (adj[i].empty())
			len[i] = 1;
		else
			for (int j = 0; j < adj[i].size(); ++j)
				len[i] = max(len[i], len[adj[i][j]] + 1);
		ans = max(ans, (long long)(len[i] * cnt[i]));
		//cout << i << ' ' << len[i] << ' ' << cnt[i] << '\n';
	}
	cout << ans << '\n';
return 0;}

