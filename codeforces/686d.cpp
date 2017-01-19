#include <bits/stdc++.h>
using namespace std;

const int MAXN = (3e5)+5;
int N, Q;
vector<int> adj[MAXN];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> N >> Q;
  for (int i = 1; i < N; ++i) {
    int p; cin >> p;
    adj[i].push_back(p-1);
  }
return 0;}

