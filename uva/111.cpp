#include <bits/stdc++.h>
using namespace std;

int N, ord[21], X, A[21];
set<int> S;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> N;
  for (int i = 1; i <= N; ++i)
    cin >> ord[i];
  while (cin >> X) {
    A[X] = ord[1];
    for (int i = 2; i <= N; ++i) {
      int tmp; cin >> tmp;
      A[tmp] = ord[i];
    }
    S.clear();
    for (int i = 1; i <= N; ++i) {
      S.insert(A[i]);
      auto it = S.find(A[i]);
      ++it;
      if (it != S.end())
        S.erase(it);
    }
    cout << S.size() << '\n';
  }
return 0;}

