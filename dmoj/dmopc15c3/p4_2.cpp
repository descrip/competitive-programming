#include <bits/stdc++.h>
using namespace std;
#define INF 100000000000000LL

inline long long hypot(long long x1, long long y1, long long x2, long long y2){
	return (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	vector<pair<int,int>> pts (N);
	for (int i = 0; i < N; ++i)
		cin >> pts[i].first >> pts[i].second;
	static long long dist[3005];
	static bool vis[3005];
	int X, Q; cin >> X >> Q;
	--X;
	fill_n(dist, 3005, INF);
	dist[X] = 0;
	while (true){
		int u = -1;
		long long best = INF;
		for (int i = 0; i < N; ++i)
			if (!vis[i] && dist[i] < best){
				u = i;
				best = dist[i];
			}
		if (best == INF)
			break;
		for (int v = 0; v < N; ++v){
			long long tmp = hypot(pts[u].first, pts[u].second, pts[v].first, pts[v].second);
			if (!vis[v] && dist[v] > dist[u] + tmp)
				dist[v] = dist[u] + tmp;
		}
		vis[u] = true;
	}
	sort(dist, dist+N);
	for (int i = 0; i < Q; ++i){
		long long t; cin >> t;
		cout << (upper_bound(dist, dist+N, t) - dist) << '\n';
	}
return 0;}

