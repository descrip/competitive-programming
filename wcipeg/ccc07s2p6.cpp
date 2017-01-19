#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int N, R, low[1001], num[1001], dfscnt = 0, par[1001], scc[1001], scccnt = 0, leafcnt = 0;
vector<int> adj[1001], adj2[1001];
vector<pair<int, int>> bri;
bool cant[1001][1001];

void findbri(int u) {
  low[u] = num[u] = ++dfscnt;
  for (int v : adj[u])
    if (num[v] == 0) {
      par[v] = u;
      findbri(v);
      if (low[v] > num[u]) {
        bri.push_back(make_pair(u, v));
        cant[u][v] = cant[v][u] = true;
      }
      low[u] = min(low[u], low[v]);
    }
    else if (par[u] != v)
      low[u] = min(low[u], low[v]);
}

void constrict(int u, int n) {
  scc[u] = n;
  for (int v : adj[u])
    if (!cant[u][v] && scc[v] == 0)
      constrict(v, n);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> N >> R;
  for (int i = 0; i < R; ++i) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 1; i <= N; ++i)
    if (num[i] == 0)
      findbri(i);
  for (int i = 1; i <= N; ++i)
    if (scc[i] == 0)
      constrict(i, ++scccnt);
  /*
  for (int i = 1; i <= N; ++i)
    cout << i << ' ' << scc[i] << '\n';
  */
  for (pair<int, int> p : bri) {
    adj2[scc[p.first]].push_back(scc[p.second]);
    adj2[scc[p.second]].push_back(scc[p.first]);
  }
  for (int i = 1; i <= scccnt; ++i)
    if (adj2[i].size() == 1)
      ++leafcnt;
  //cout << leafcnt << '\n';
  cout << (int)ceil(leafcnt/2.0) << '\n';
  /*
  for (int i = 1; i <= N; ++i)
    cout << i << ' ' << num[i] << ' ' << low[i] << '\n';
  for (int i = 0; i < bri.size(); ++i)
    cout << bri[i].first << ' ' << bri[i].second << '\n';
    */
return 0;}

