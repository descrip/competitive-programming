#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  string S;
  deque<char> dq;
  while (getline(cin, S)) {
    for (char c : S)
      dq.push_back(c);
    while (true) {
      int num = 0;
      if (dq.empty())
        break;
      while (0 <= dq.front() - '0' && dq.front() - '0' < 10) {
        num += dq.front() - '0';
        dq.pop_front();
      }
      for (int i = 0; i < num; ++i)
        cout << (dq.front() == 'b' ? ' ' : dq.front());
      dq.pop_front();
      if (dq.empty())
        break;
      if (dq.front() == '!') {
        dq.pop_front();
        cout << '\n';
      }
    }
    cout << '\n';
  }
return 0;}

