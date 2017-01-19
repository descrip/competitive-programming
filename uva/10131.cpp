#include <bits/stdc++.h>
using namespace std;

struct ele {
  int wei, ind, id;
};

bool elesort(const ele &a, const ele &b) {
  return a.wei < b.wei;
}

int N = 0, dp[1001], ans = 0;
ele A[1001];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  while (cin >> A[N].wei >> A[N].ind) {
    A[N].id = N+1;
    N++;
  }
  sort(A, A+N, elesort);
  fill_n(dp, 1001, 1);
  for (int i = 1; i < N; ++i) {
    for (int j = 0; j < i; ++j)
      if (A[j].ind > A[i].ind && A[j].wei < A[i].wei)
        dp[i] = max(dp[j]+1, dp[i]);
    ans = max(ans, dp[i]);
  }

  /*
  for (int i = 0; i < N; ++i)
    cout << A[i].id << ' ' << A[i].wei << ' ' << A[i].ind << '\n';
  for (int i = 0; i < N; ++i)
    cout << dp[i] << ' ';
  cout << '\n';
  */

  cout << ans << '\n';
  vector<int> wow;
  int last = 0;
  for (int i = N-1; i >= 0; --i)
    if (dp[i] == ans && A[i].ind > last) {
      wow.push_back(i);
      last = A[i].ind;
      --ans;
    }
  while (!wow.empty()) {
    //cout << A[wow.back()].id << ' ' << A[wow.back()].wei << ' ' << A[wow.back()].ind << '\n';
    cout << A[wow.back()].id << '\n';
    wow.pop_back();
  }
return 0;}

