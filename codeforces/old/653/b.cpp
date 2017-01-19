#include <bits/stdc++.h>
using namespace std;

int N, Q;
map<string, bool> vis;
vector<string> M['a'+30];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> N >> Q;
  for (int i = 0; i < Q; ++i) {
    string s; char c; cin >> s >> c;
    M[c].push_back(s);
  }
  queue<string> q;
  q.push("a");
  long long ans = 0;
  while (!q.empty()) {
    string curr = q.front(); q.pop();
    //cout << curr << '\n';
    if (vis[curr])
      continue;
    vis[curr] = true;
    if (curr.size() == N) {
      ++ans; continue;
    }
    for (int i = 0; i < 1; ++i)
      for (string s : M[curr[i]])
        q.push(curr.substr(0,i) + s + (i+1 < N ? curr.substr(i+1) : ""));
  }
  cout << ans << '\n';
return 0;}

