#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> V, adj[100001];
bool vis[100001];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> N >> M;
  for (int i = 0; i < N; ++i)
    V.push_back(i+1);
  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int cnt = 0, sim = 0;
  for (int pos = V.size()-1; pos > 0; --pos) {
    vis[V[pos]] = true;
    for (int i : adj[V[pos]])
      if (vis[i])
        break;
    sim += adj[V[pos]].size();
    if (sim == M)
      ++cnt;
  }
  cout << cnt << '\n';
return 0;}

