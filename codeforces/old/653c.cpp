#include <bits/stdc++.h>
using namespace std;

#define DEBUG false 
const int MAXN = 150003;
int N, A[MAXN];
vector<int> bad;

bool ok(int pos) {
  if (!(1 <= pos && pos < N))
    return true;
  else if (pos % 2 == 0)
    return A[pos] > A[pos+1];
  else
    return A[pos] < A[pos+1];
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> N;
  for (int i = 1; i <= N; ++i)
    cin >> A[i];
  for (int i = 1; i < N; ++i)
    if (!ok(i)) {
      bad.push_back(i);
      //bad.push_back(i+1);
    }

  sort(bad.begin(), bad.end());
  if (bad.size() > 4) {
  /*
  if (bad.size() > 4 ||
      (bad.size() == 3 && !(bad[0]+1 == bad[1] || bad[1]+1 == bad[2])) ||
      (bad.size() == 4 && !(bad[0]+1 == bad[1] && bad[1]+1 == bad[2]))) {
      */
    cout << "0\n";
    return 0;
  }

  set<pair<int, int>> ans;
  for (int i : bad) {
    for (int j = 1; j <= N; ++j) {
      if (i == j)
        continue;
      swap(A[i], A[j]);
      bool good = true;
      for (int k : bad)
        if (!ok(k))
          good = false;
      if (!ok(j) || !ok(j-1) || !ok(i-1))
        good = false;

      if (DEBUG) {
        cout << i << ' ' << j << ' ';
        for (int a = 1; a <= N; ++a)
          cout << A[a] << ' ';
        cout << '\n';
        cout << "    ";
        for (int a = 1; a <= N; ++a)
          cout << ok(a) << ' ';
        cout << '\n';
      }

      if (good)
        ans.insert({min(i, j), max(i, j)});
      swap(A[i], A[j]);
    }

    for (int j = 1; j <= N; ++j) {
      if (i+1 == j)
        continue;
      swap(A[i+1], A[j]);
      bool good = true;
      for (int k : bad)
        if (!ok(k))
          good = false;
      if (!ok(j) || !ok(j-1))
        good = false;

      if (DEBUG) {
        cout << i << ' ' << j << ' ';
        for (int a = 1; a <= N; ++a)
          cout << A[a] << ' ';
        cout << '\n';
        cout << "    ";
        for (int a = 1; a <= N; ++a)
          cout << ok(a) << ' ';
        cout << '\n';
      }

      if (good)
        ans.insert({min(i+1, j), max(i+1, j)});
      swap(A[i+1], A[j]);
    }
  }

  cout << ans.size() << '\n';
return 0;}

