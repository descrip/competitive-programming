#include <bits/stdc++.h>
using namespace std;

int C, N;
bool dp[1000][1000][2], vis[1000][1000][2], adj[1000][1000];

int zmod(int a, int m) {
  return ((a % m) + m) % m;
}

bool recur(int pos, int len, bool which) {
  //cout << pos << ' ' << len << ' ' << which << '\n';
  if (len == 0)
    return true;
  if (vis[pos][len][which])
    return dp[pos][len][which];
  vis[pos][len][which] = true;
  return (dp[pos][len][which] =
      (adj[(which ? zmod(pos-1, C) : zmod(pos+len, C))][pos] && recur(zmod(pos+1, C), len-1, true)) ||
      (adj[zmod(pos+len-1, C)][(which ? zmod(pos-1, C) : zmod(pos+len, C))] && recur(pos, len-1, false))
    );
}

void wow(int pos, int len, bool which) {
  if (len == 0)
    return;
  else if (adj[(which ? zmod(pos-1, C) : zmod(pos+len, C))][pos] && recur(zmod(pos+1, C), len-1, true)) {
    cout << pos+1 << '\n';
    wow(zmod(pos+1, C), len-1, true);
  }
  else if (adj[zmod(pos+len-1, C)][(which ? zmod(pos-1, C) : zmod(pos+len, C))] && recur(pos, len-1, false)) {
    cout << zmod(pos+len-1, C)+1 << '\n';
    wow(pos, len-1, false);
  }
} 

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> C >> N;
  for (int i = 0; i < N; ++i) {
    int a, b; cin >> a >> b;
    adj[a-1][b-1] = adj[b-1][a-1] = true;
  }
  for (int i = 0; i < N; ++i)
    if (recur(zmod(i+1, C), C-1, 0)) {
      cout << i+1 << '\n';
      wow(zmod(i+1, C), C-1, 0);
      return 0;
    }
  cout << "-1\n";
return 0;}

