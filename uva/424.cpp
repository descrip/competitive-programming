#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  static char A[128][128];
  fill_n(A[0], 128*128, '0');
  string S;
  for (int i = 0; i < 100; ++i) {
    cin >> S;
    if (S == "0")
      break;
    for (int j = S.size()-1; j >= 0; --j)
      A[i][S.size()-j-1] = S[j];
  }
  int carry = 0;
  string ans = "";
  for (int pos = 0; pos < 128; ++pos) {
    int tmp = carry;
    for (int i = 0; i < 100; ++i)
      tmp += (A[i][pos] - '0');
    carry = tmp/10;
    tmp %= 10;
    ans += (char)('0'+tmp);
  }
  reverse(ans.begin(), ans.end());
  int wow = 0;
  while (ans[wow] == '0')
    ++wow;
  cout << ans.substr(wow) << '\n';
return 0;}

