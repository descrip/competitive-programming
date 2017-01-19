#include <bits/stdc++.h>
using namespace std;

string wow[101], line = "ivxlc";
vector<int> num = {1, 4, 5, 9, 10, 40, 50, 90, 100};
int cnt[101][5];

string recur(int n) {
  if (n == 0)
    return "";
  auto it = upper_bound(num.begin(), num.end(), n);
  --it;
  return wow[*it] + recur(n-*it);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  wow[1] = "i";
  wow[4] = "iv";
  wow[5] = "v";
  wow[9] = "ix";
  wow[10] = "x";
  wow[40] = "xl";
  wow[50] = "l";
  wow[90] = "xc";
  wow[100] = "c";
  for (int i = 1; i <= 100; ++i) {
    string s = recur(i);
    for (int j = 0; j < 5; ++j)
      cnt[i][j] += cnt[i-1][j];
    for (char c : s)
      ++cnt[i][line.find(c)];
  }
  int n;
  while (cin >> n) {
    if (n == 0)
      break;
    cout << n << ": ";
    for (int i = 0; i < 5; ++i) {
      cout << cnt[n][i] << ' ' << line[i];
      if (i != 4)
        cout << ", ";
      else
        cout << '\n';
    }
  }
return 0;}

