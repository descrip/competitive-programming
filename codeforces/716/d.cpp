#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = (1e9)+7;
int N, M, S, T, pre[1005];
vector<int> path;
set<int> adj[1005];
vector<pair<int, int>> edges, varEdges;
ll L, wei[1005][1005], dist[1005];
bool isVarEdge[1005][1005];

struct pointerSort {
	bool operator() (const pair<long long*, int> &a, const pair<long long*, int> &b) {
		return *(a.first) < *(b.first);
	}
};

void dijk(int S) {
	priority_queue<pair<long long*, int>, vector<pair<long long*, int>>, pointerSort> pq;

	fill_n(pre, 1005, -1);
	fill_n(dist, 1005, INF);
	dist[S] = 0;
	pq.push(make_pair(&dist[S], S));

	while (!pq.empty()) {
		int x = pq.top().second;
		pq.pop();

		for (int i : adj[x]) {
			long long alt = dist[x] + wei[x][i];
			if (alt < dist[i]) {
				if (dist[i] == INF)
				pq.push(make_pair(&dist[i], i));
				dist[i] = alt;
				pre[i] = x;
			}
		}
	}
}

void dijk2(int S) {
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

	fill_n(pre, 1005, -1);
	fill_n(dist, 1005, INF);
	dist[S] = 0;

	pq.push({0, S});

	while (!pq.empty()) {
		long long d = pq.top().first;
		int x = pq.top().second;
		pq.pop();
		if (d > dist[x])
			continue;
		for (int i : adj[x]) {
			long long alt = dist[x] + wei[x][i];
			if (alt < dist[i]) {
				dist[i] = alt;
				pre[i] = x;
				pq.push({dist[i], i});
			}
		}
	}
}

int main() {

	dist[3] = 3;
	dist[4] = 4;
	pair<long long*, int> a = make_pair(&dist[3], 1),
		b = make_pair(&dist[4], 1);
	//priority_queue<
	//	pair<long long*, int>,
	//	vector<pair<long long*, int>>,
	//	pointerSort> pq;
	//pq.push(a);
	//pq.push(b);
	//cout << *pq.top().first << '\n';
	//dist[3] = 800;
	//cout << *pq.top().first << '\n';

	set<pair<long long*, int>, pointerSort> wow;
	wow.insert(a);
	wow.insert(b);
	cout << *(*wow.begin()).first << '\n';
	dist[3] = 8000;
	cout << *(*wow.begin()).first << '\n';

	//dist[3] = 20210;
	//cout << *a.first << ' ' << a.second << '\n';
	//cout << *b.first << ' ' << b.second << '\n';
	//cout << pointerSort()(a, b) << '\n';

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M >> L >> S >> T;
	for (int i = 0; i < M; ++i) {
		int u, v;
		long long w;
		cin >> u >> v >> w;
		adj[u].insert(v);
		adj[v].insert(u);
		wei[u][v] = wei[v][u] = w;
		edges.push_back({u, v});
		if (wei[u][v] == 0) {
			varEdges.push_back({u, v});
			isVarEdge[u][v] = isVarEdge[v][u] = true;
		}
	}

	for (auto p : varEdges) {
		adj[p.first].erase(p.second);
		adj[p.second].erase(p.first);
	}

	dijk(S);
	if (dist[T] < L) {
		cout << "NO\n";
		return 0;
	}

	for (auto p : varEdges) {
		adj[p.first].insert(p.second);
		adj[p.second].insert(p.first);
		wei[p.first][p.second] = wei[p.second][p.first] = 1;
	}

	dijk(S);
	if (dist[T] > L) {
		cout << "NO\n";
		return 0;
	}

	int tmp = T;
	while (tmp != -1) {
		path.push_back(tmp);
		tmp = pre[tmp];
	}
	reverse(path.begin(), path.end());

	for (int i = 0; i < path.size()-1; ++i)
		if (isVarEdge[path[i]][path[i+1]])
			wei[path[i]][path[i+1]] = wei[path[i+1]][path[i]] = -1;
	for (auto p : varEdges)
		if (wei[p.first][p.second] == -1)
			wei[p.first][p.second] = wei[p.second][p.first] = 1;
		else
			wei[p.first][p.second] = wei[p.second][p.first] = INF;

	//cout << wei[1][4] << '\n';

	/*
	for (auto i : path)
		cout << i << ' ';
	cout << '\n';
	*/

	long long curr = dist[T];
	for (int i = 0; i < path.size()-1; ++i) {
		if (L == curr)
			break;
		if (!isVarEdge[path[i]][path[i+1]])
			continue;
		//cout << path[i] << ' ' << path[i+1] << '\n';

		int u = path[i], v = path[i+1];
		adj[u].erase(v);
		adj[v].erase(u);

		dijk(S);
		long long tmp = min(L, dist[T]) - curr;
		wei[u][v] += tmp;
		wei[v][u] += tmp;
		curr += tmp;

		adj[u].insert(v);
		adj[v].insert(u);

		//dijk(S);
		//curr = dist[T];

		if (curr == L) {
			dijk(S);
			if (dist[T] != L)
				cout << "): " << dist[T] << '\n';
			cout << "YES\n";
			for (auto p : edges)
				cout << p.first << ' ' << p.second << ' ' << wei[p.first][p.second] << '\n';
			return 0;
		}
	}

	if (curr == L) {
		dijk(S);
		if (dist[T] != L)
			cout << "): " << dist[T] << '\n';
		cout << "YES\n";
		for (auto p : edges)
			cout << p.first << ' ' << p.second << ' ' << wei[p.first][p.second] << '\n';
		return 0;
	}

	cout << "NO\n";

	return 0;
}

