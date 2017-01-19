#include <bits/stdc++.h>
using namespace std;

int N, K, A[100005], C[100005], l = 0, r = 0, ans = 0;
vector<int> V;
set<int> S;
multiset<int> E;

int main(){
	//ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    V.push_back(A[i]);
  }
  sort(V.begin(), V.end());
  unique(V.begin(), V.end());
  for (int i = 0; i < N; ++i)
    A[i] = (lower_bound(V.begin(), V.end(), A[i]) - V.begin());
  for (; r < N; ++r) {
    ++C[A[r]];
    if (C[A[r]] == 1) {
      S.insert(A[r]);
      E.insert(1);
    }
    else {
      E.erase(E.find(C[A[r]-1]));
      E.insert(C[A[r]]);
    }
    while (S.size() > K+1) {
      E.erase(E.find(C[A[l]]));
      --C[A[l]];
      if (C[A[l]] == 0)
        S.erase(A[l]);
      else
        E.insert(C[A[l]]);
      ++l;
    }
    ans = max(ans, *E.rbegin());
  }
  cout << ans << '\n';
return 0;}

