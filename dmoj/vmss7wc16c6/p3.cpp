#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int N, M, low[MAXN+1], num[MAXN+1], par[MAXN+1], rchi, root, cnt = 1, ans = 0;
vector<int> adj[MAXN+1];
bool art[MAXN+1];

void findart(int u){
	low[u] = num[u] = cnt++;
	for (int v : adj[u]){
		if (num[v] == 0){
			par[v] = u;
			if (u == root) ++rchi;
			findart(v);
			if (low[v] >= num[u])
				art[u] = true;
			low[u] = min(low[u],low[v]);
		}
		else if (v != par[u])
			low[u] = min(low[u],num[v]);
	}
	//cout << u << ' ' << num[u] << ' ' << low[u] << '\n';
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	assert(1 <= N && N <= 100000);
	assert(1 <= M && M <= 1000000);
	//set<pair<int, int>> uniq;
	for (int i = 0; i < M; ++i){
		int x, y; cin >> x >> y;
		assert(1 <= x && x <= N && 1 <= y && y <= N);
		//uniq.insert({min(x, y), max(x, y)});
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	/*
	static bool vis[100001];
	queue<int> q;
	q.push(1);
	int cnt = 0;
	while (!q.empty()){
		int x = q.front();
		q.pop();
		if (vis[x])
			continue;
		vis[x] = true;
		++cnt;
		if (cnt == N)
			break;
		for (int i : adj[x])
			if (!vis[i])
				q.push(i);
	}
	for (int i = 1; i <= N; ++i)
		assert(vis[i]);
	assert(uniq.size() == M);
	*/

	for (int i = 1; i <= N; ++i)
		if (num[i] == 0){
			root = i; rchi = 0;
			findart(i);
			art[root] = rchi > 1;
		}
	ans = 0;
	for (int i = 1; i <= N; ++i)
		if (art[i])
			++ans;
	cout << ans << '\n';
	for (int i = 1; i <= N; ++i)
		if (art[i])
			cout << i << '\n';

	/*
	while (true){
		cin >> N;
		if (N == 0) break;
		fill(adj,adj+MAXN,vector<int>());
		fill(art,art+MAXN,false);
		fill(low,low+MAXN,0);
		fill(num,num+MAXN,0);
		fill(par,par+MAXN,0);
		cnt = 1;
		cin.ignore(256,'\n');
		while (true){
			string s; getline(cin,s);
			istringstream iss (s);
			int a, b; iss >> a;
			if (a == 0) break;
			while (iss >> b){
				adj[a].push_back(b);
				adj[b].push_back(a);
			}
		}
		for (int i = 1; i <= N; ++i)
			if (num[i] == 0){
				root = i; rchi = 0;
				findart(i);
				art[root] = rchi > 1;
			}
		ans = 0;
		for (int i = 1; i <= N; ++i)
			if (art[i])
				++ans;
		cout << ans << '\n';
	}
	*/
return 0;}

