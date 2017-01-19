#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000, MOD = 1000000000;
int N, cnt[2];
set<pair<int, int>> pts[2], added[2];
map<pair<int, int>, int> look[2];
set<int> adj[2][MAXN];
long long wei[2][MAXN], sum[2][MAXN];

void recur(int x, int y, int id, int ind){
	if (added[ind].count(make_pair(x, y)) != 0)
		return;
	added[ind].insert({x, y});
	int tx = x, ty = y, bx = x, by = y;
	queue<pair<int, int>> q;
	for (int c = -1; c <= 1; ++c)
		if (pts[ind].count(make_pair(x+c, y)) != 0 && added[ind].count(make_pair(x+c, y)) == 0)
			q.push({x+c, y});
	while (pts[ind].count({tx, ty-1}) != 0){
		--ty;
		added[ind].insert(make_pair(tx, ty));
		for (int c = -1; c <= 1; c+=2)
			if (pts[ind].count(make_pair(tx+c, ty)) != 0 && added[ind].count(make_pair(tx+c, ty)) == 0)
				q.push({tx+c, ty});
	}
	while (pts[ind].count({bx, by+1}) != 0){
		++by;
		added[ind].insert(make_pair(bx, by));
		for (int c = -1; c <= 1; c+=2)
			if (pts[ind].count(make_pair(bx+c, by)) != 0 && added[ind].count(make_pair(bx+c, by)) == 0)
				q.push({bx+c, by});
	}
	while (!q.empty()){
		pair<int, int> p = q.front(); q.pop();
		adj[ind][id].insert(++cnt[ind]);
		recur(p.first, p.second, cnt[ind], ind);
	}
	wei[ind][id] = by - ty + 1;
	//cout << id << ' ' << tx << ' ' << ty << ' ' << by << ' ' << wei[ind][id] << '\n';
}

long long recurSum(int pos, int ind){
	long long ret = wei[ind][pos];
	for (int i : adj[ind][pos]){
		//cout << "A " << pos << ' ' << i << '\n';
		ret = (ret + recurSum(i, ind)) % MOD;
	}
	//cout << "B " << pos << ' ' << ret << '\n';
	return (sum[ind][pos] = ret);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i){
		int x, y; cin >> x >> y;
		pts[0].insert({x, y});
		pts[1].insert({y, x});
	}
	recur(pts[0].begin()->first, pts[0].begin()->second, 0, 0);
	recur(pts[1].begin()->first, pts[1].begin()->second, 0, 1);
	recurSum(0, 0);
	recurSum(0, 1);
	//cout << *adj[0][0].begin() << '\n';
	long long ans = 0;
	for (int k = 0; k <= 1; ++k)
		for (int i = 0; i < cnt[k]; ++i)
			for (int j : adj[k][i])
				ans = (ans + (N - sum[k][j]) * sum[k][j]) % MOD;
	cout << ans << '\n';
return 0;}

