#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1000003;
int N, P[MAXN], par[MAXN], root = 0, best = 2000000001, ans = -1, cnt[MAXN];
vector<int> zadj[MAXN], adj[MAXN];
bool vis[MAXN];

int direc(int n, int l) {
  vis[n] = true;
  par[n] = l;
  for (int i : zadj[n])
    if (!vis[i]) {
      cnt[n] += direc(i, n);
      adj[n].push_back(i);
    }
  cnt[n] += P[n];
  return cnt[n];
}

void gao(int n, int in) {
  int curr = in;
  for (int i : adj[n])
    curr = max(curr, cnt[i]);
  if (curr < best) {
    best = curr;
    ans = n;
  }
  int tot = 0;
  for (int i : adj[n])
    tot += cnt[i];
  //cout << n << ' ' << in << ' ' << tot << '\n';
  for (int i : adj[n])
    gao(i, P[n] + tot - cnt[i] + in);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; ++i)
    cin >> P[i];
  for (int i = 0; i < N-1; ++i) {
    int a, b; cin >> a >> b;
    zadj[a].push_back(b);
    zadj[b].push_back(a);
  }
  while (zadj[root].size() != 1)
    break;
  cnt[root] = direc(root, -1);
  gao(root, 0);
  /*
  for (int i = 0; i < N; ++i)
    cout << i << ' ' << cnt[i] << '\n';
    */
  cout << ans << '\n';
return 0;}

