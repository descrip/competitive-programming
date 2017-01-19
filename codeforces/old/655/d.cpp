#include <bits/stdc++.h>
using namespace std;

int N, M, lastK = 0;
pair<int, int> A[100002];
vector<int> adj[100002], radj[100002];
bool vis[100002];

bool poss(int K) {
  fill_n(vis, 100002, false);
  if (K > lastK) {
    for (int i = lastK; i < K; ++i) {
      adj[A[i].first].push_back(A[i].second);
      radj[A[i].second].push_back(A[i].first);
    }
  }
  else if (K < lastK) {
    for (int i = lastK-1; i >= K; --i) {
      adj[A[i].first].pop_back();
      radj[A[i].second].pop_back();
    }
  }
  //cout << "wow " << radj[1].size() << '\n';
  lastK = K;
  int pos = 1;
  for (int i = 2; i <= N; ++i)
    if (radj[i].empty()) {
      if (radj[pos].empty())
        return false;
      pos = i;
    }
  //cout << adj[2].size() << ' ' << radj[2].size() << '\n';
  int cnt = 0;
  while (true) {
    //cout << pos << '\n';
    int next = -1;
    ++cnt;
    vis[pos] = true;
    for (int v : adj[pos]) {
      bool ok = true;
      for (int u : radj[v])
        if (!vis[u]) {
          //cout << "! " << u << ' ' << v << '\n';
          ok = false;
          break;
        }
      if (ok && next != -1)
        return false;
      else if (ok)
        next = v;
    }
    if (next == -1) {
      //cout << K << ' ' << cnt << '\n';
      return cnt == N;
    }
    pos = next;
  }
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> N >> M;
  for (int i = 0; i < M; ++i) 
    cin >> A[i].first >> A[i].second;
  int lo = 1, hi = M, mid;
  while (lo < hi) {
    mid = lo + (hi-lo)/2;
    //cout << lo << '\n';
    //cout << lo << ' ' << hi << '\n';
    if (!poss(mid))
      lo = mid+1;
    else
      hi = mid;
    //cout << '\n';
  }
  if (lo == M && !poss(lo))
    cout << "-1\n";
  else
    cout << lo << '\n';
return 0;}

