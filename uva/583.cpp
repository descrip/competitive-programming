#include <bits/stdc++.h>
using namespace std;

const int LEN = sqrt(0x7fffffff);
int n;
bool isp[LEN];
vector<int> pri;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  isp[0] = isp[1] = true;
  for (int i = 2; i*i < LEN; ++i)
    if (!isp[i])
      for (int j = 2; i*j < LEN; ++j)
        isp[i*j] = true;
  for (int i = 0; i < LEN; ++i)
    if (!isp[i])
      pri.push_back(i);

  while (cin >> n) {
    if (n == 0)
      break;
    cout << n << " = ";
    bool first = true;
    if (n < 0) {
      n *= -1;
      cout << "-1";
      first = false;
    }
    for (int i = 0; pri[i]*pri[i] <= n && i < pri.size(); ++i)
      while (n % pri[i] == 0) {
        n /= pri[i];
        cout << (first ? "" : " x ") << pri[i];
        first = false;
      }
    if (n > 1)
      cout << (first ? "" : " x ") << n;
    cout << '\n';
  }
return 0;}

