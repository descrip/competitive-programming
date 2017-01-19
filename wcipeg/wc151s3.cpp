#include <bits/stdc++.h>
using namespace std;

const int MAXN = (1e5)+5;
int N, M, K, C[MAXN], dist1[MAXN], dist2[MAXN];
vector<pair<int, int>> adj[MAXN], ord;
long long ans = 0;

void dijk(int root, int arr[]){
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, root});
	fill_n(arr, MAXN, -1);
	while (!pq.empty()){
		int pos = pq.top().second, dist = pq.top().first;
		pq.pop();
		if (arr[pos] != -1)
			continue;
		arr[pos] = dist;
		for (pair<int, int> v : adj[pos])
			if (arr[v.first] == -1)
				pq.push({dist + v.second, v.first});
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; ++i)
		cin >> C[i];
	for (int i = 1; i <= M; ++i){
		int x, y, z; cin >> x >> y >> z;
		adj[y].push_back({x, z});
	}
	dijk(1, dist1); dijk(2, dist2);
	for (int i = 1; i <= N; ++i){
		if (C[i] == 0)
			continue;	//why am i dumb
		else if (dist1[i] == -1 && dist2[i] == -1){
			cout << "-1\n";
			return 0;
		}
		else if (dist1[i] == -1){
			if (K < C[i]){
				cout << "-1\n";
				return 0;
			}
			K -= C[i];
			ans += 1LL * C[i] * dist2[i];
		}
		else if (dist2[i] == -1)
			ans += 1LL * C[i] * dist1[i];
		else
			ord.push_back({dist2[i] - dist1[i], i});
	}
	sort(ord.begin(), ord.end());
	for (pair<int, int> p : ord){
		//cout << p.second << ' ' << dist1[p.second] << ' ' << dist2[p.second] << ' ' << C[p.second] << ' ' << K << '\n';
		if (dist2[p.second] < dist1[p.second]){
			int tmp = min(K, C[p.second]);
			K -= tmp;
			ans += 1LL * tmp * dist2[p.second];
			ans += 1LL * (C[p.second] - tmp) * dist1[p.second];
		}
		else
			ans += 1LL * C[p.second] * dist1[p.second];
	}
	cout << ans << '\n';
return 0;}

