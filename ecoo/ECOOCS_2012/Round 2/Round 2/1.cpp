#include <bits/stdc++.h>
using namespace std;

#define NUM_TESTS 5
int N;
bool isp[500001];
vector<int> pri, mes;
string key = " ABCDEFGHIJKLMNOPQRSTUVWXYZ.,!?";

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  fill_n(isp, 500001, true);
  isp[0] = isp[1] = false;
  for (int i = 2; i*i <= 500000; ++i)
    if (isp[i])
      for (int j = 2; i*j <= 500000; ++j)
        isp[i*j] = false;
  for (int i = 100000; i < 500000; ++i)
    if (isp[i])
      pri.push_back(i);
  for (int t = 0; t < NUM_TESTS; ++t) {
    cin >> N;
    mes.assign(N, 0);
    for (int i = 0; i < N; ++i)
      cin >> mes[i];
    for (int p : pri) {
      bool ok = false;
      for (int i = 0; i < N; ++i)
        if (mes[i] % p != 0)
          break;
        else if (i == N-1) {
          ok = true;
          for (int j = 0; j < N; ++j) {
            int tmp = mes[j] / p;
            cout << key[tmp/100] << key[tmp%100];
          }
        }
      if (ok)
        break;
    }
    cout << '\n';
  }
return 0;}

