#include <iostream>
using namespace std;

int N;
bool A[91];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int a; cin >> a;
    A[a] = true;
  }
  int cnt = 0, ans = 0;
  for (int i = 1; i <= 90; ++i) {
    if (A[i])
      cnt = 0;
    else
      ++cnt;
    ++ans;
    if (cnt == 15)
      break;
  }
  cout << ans << '\n';
return 0;}

