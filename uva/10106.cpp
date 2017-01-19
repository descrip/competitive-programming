#include <bits/stdc++.h>
using namespace std;

string S, T;
char A[501][501];

void multi(int pos, string s, int t) {
  int carry = 0, i;
	for (i = s.size()-1; i >= 0; --i) {
    int tmp = (s[i] - '0') * t + carry;
    carry = tmp/10;
    tmp %= 10;
    A[pos][s.size()-i-1] = '0' + tmp;
  }
  while (carry) {
    A[pos][s.size()-i-1] = '0' + carry % 10;
    carry /= 10;
    --i;
  }
}

int main() {
	while (cin >> S >> T) {
    if (S == "0" || T == "0") {
      cout << "0\n";
      continue;
    }
    fill_n(A[0], 501*501, '0');
    for (int i = T.size()-1; i >= 0; --i) {
      multi(T.size()-i-1, S, T[i]-'0');
      S += '0';
    }
    int carry = 0;
    string ans = "";
    for (int i = 0; i <= 500; ++i) {
      int tmp = 0;
      for (int j = 0; j <= 500; ++j)
        tmp += (A[j][i] - '0');
      tmp += carry;
      carry = tmp/10;
      tmp %= 10;
      ans += ('0' + tmp);
    }
    while (carry) {
      ans += '0' + carry%10;
      carry /= 10;
    }
    reverse(ans.begin(), ans.end());
    int pos = 0;
    while (ans[pos] == '0')
      ++pos;
    cout << ans.substr(pos) << '\n';
	}
}
