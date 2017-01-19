#include <iostream>
#include <queue>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define INF 0xfffffff
int N, T, adj[5001][5001], K, P[5001], D, ans = 0xfffffff, cnt = 0;
bool vis[5001];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  scan(N); scan(T);
  fill_n(adj[0], 5001*5001, INF);
  fill_n(P, 5001, INF);
  for (int t = 0; t < T; ++t) {
    int a, b, c; scan(a); scan(b); scan(c);
    adj[a][b] = min(adj[a][b], c);
    adj[b][a] = adj[a][b];
  }
  scan(K);
  for (int k = 0; k < K; ++k) {
    int a, b; scan(a); scan(b);
    P[a] = b;
  }
  scan(D);

  priority_queue<pair<int, int>, vector<pair<int ,int>>, greater<pair<int, int>>> pq;
  pq.push(make_pair(0, D));
  while (!pq.empty()) {
    int d = pq.top().first, x = pq.top().second;
    pq.pop();
    if (vis[x])
      continue;
    vis[x] = true;
    ans = min(ans, P[x] + d);
    for (int v = 1; v <= N; ++v)
      if (adj[x][v] != INF && !vis[v])
        pq.push(make_pair(adj[x][v] + d, v));
    ++cnt;
    if (cnt == N) {
      cout << ans << '\n';
      return 0;
    }
  }
return 0;}

