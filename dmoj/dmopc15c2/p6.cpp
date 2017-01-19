#include <bits/stdc++.h>
using namespace std;

//TODO: Holy shit how to represent???

#define fi first
#define se second

inline int manhat(const pair<int, int> &a, const pair<int, int> &b){
	return abs(a.first - b.first) + abs(a.second - b.second);
}

struct event{
	int when;
	bool typ;
	pair<int, int> ran;
	event(int a, bool b, pair<int, int> c): when(a), typ(b), ran(c) {}
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int M; cin >> M;
	vector<pair<int, int>> mag (M);
	for (int i = 0; i < M; ++i)
		cin >> mag[i].fi >> mag[i].se;
	int N; cin >> N;
	vector<pair<int, int>> met (N);
	for (int i = 0; i < N; ++i)
		cin >> met[i].fi >> met[i].se;

	vector<int> dist (N);
	fill_n(dist, N, 0xfffffff);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			dist[i] = min(dist[i], manhat(met[i], mag[j]));

	vector<event> E;
	for (int i = 0; i < N; ++i){
		int sum = mag[i].fi + mag[i].se;
		E.push_back(event(
			max(0, sum - (dist[i] - 2)),
			true,
			sum/2 - mag[i].fi,
			sum/2 - mag[i].se));
	}
return 0;}

