#include <bits/stdc++.h>
using namespace std;

//TODO: Check if cases handled

int T, N, par[105], ran[105];
pair<double, double> A[105];
vector<pair<double, pair<int, int>>> D;

double dist(const pair<double, double> &a, const pair<double, double> &b) {
  return sqrt((a.first - b.first) * (a.first - b.first) +
         (a.second - b.second) * (a.second - b.second));
}

int findset(int x) {
  return (par[x] == x ? x : (par[x] = findset(par[x])));
}

void unionset(int x, int y) {
  int a = findset(x), b = findset(y);
  if (ran[a] > ran[b])
    par[b] = a;
  else {
    par[a] = b;
    if (ran[b] == ran[a])
      ++ran[b];
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> T;
  for (int t = 0; t < T; ++t) {
    cin >> N;
    for (int i = 1; i <= N; ++i)
      cin >> A[i].first >> A[i].second;
    D.clear();
    for (int i = 1; i <= N; ++i)
      for (int j = i+1; j <= N; ++j)
        D.push_back({dist(A[i], A[j]), {i, j}});
    sort(D.begin(), D.end());
    /*
    for (auto p : D)
      cout << p.first << ' ' << p.second.first << ' ' << p.second.second << '\n';
      */
    for (int i = 1; i <= N; ++i) {
      par[i] = i;
      ran[i] = 1;
    }
    double ans = 0;
    for (int i = 0; i < D.size(); ++i)
      if (findset(D[i].second.first) != findset(D[i].second.second)) {
        ans += D[i].first;
        unionset(D[i].second.first, D[i].second.second);
      }
    cout << fixed << setprecision(2) << ans << '\n';
    if (t != T-1)
      cout << '\n';
  }
return 0;}

