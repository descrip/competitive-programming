#include <bits/stdc++.h>
using namespace std;

const int MAXN = (1e5)+5;
int N, sz[MAXN], d[MAXN];
vector<int> adj[MAXN];

void dfs(int u) {
  sz[u] = 1;
  for (int v : adj[u]) {
    d[v] = d[u]+1;
    dfs(v);
    sz[u] += sz[v];
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> N;
  for (int i = 1; i < N; ++i) {
    int p; cin >> p;
    adj[p-1].push_back(i);
  }
  dfs(0);
  for (int i = 0; i < N; ++i)
    cout << fixed << setprecision(8) << (N-sz[i]-d[i])/2.0 + d[i]+1 << " \n"[i==N-1];
return 0;}

