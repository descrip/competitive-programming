#include <bits/stdc++.h>
using namespace std;

int N, D, H;
vector<pair<int, int>> E;
bool vis[100005];

void cant() {
  cout << "-1\n";
  exit(0);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> N >> D >> H;
  if (H*2 < D || H > D || (H == 1 && D == 1 && N != 2))
    cant();
  vis[1] = true;
  for (int i = 2; i <= H+1; ++i) {
    vis[i] = true;
    E.push_back({i, i-1});
  }
  if (H < D) {
    E.push_back({1, H+2});
    vis[H+2] = true;
    for (int i = H+3; i <= H+1+D-H; ++i) {
      E.push_back({i, i-1});
      vis[i] = true;
    }
    for (int i = 1; i <= N; ++i)
      if (!vis[i])
        E.push_back({1, i});
  }
  else if (H == D) {
    /*
    E.push_back({H+2, (1+H+1)/2});
    vis[H+2] = true;
    for (int i = H+3; i < H+2+H/2; ++i) {
      E.push_back({i-1, i});
      vis[i] = true;
    }
    int last = (1+H+1)/2;
    for (int i = 1; i <= N; ++i)
      if (!vis[i]) {
        E.push_back({last, i});
        last = i;
      }
      */
    int cnt = 0, last = (1+H+1)/2;
    for (int i = 1; i <= N; ++i)
      if (!vis[i]) {
        E.push_back({last, i});
        ++cnt;
        if (cnt == H/2) {
          cnt = 0;
          last = (1+H+1)/2;
        }
        else
          last = i;
      }
  }
  for (int i = 0; i < E.size(); ++i)
    cout << E[i].first << ' ' << E[i].second << '\n';
return 0;}

