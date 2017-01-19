#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> V;

bool check(int k) {
  V.clear();
  for (int i = 1; i <= N; ++i)
    V.push_back(i);
  int tick = k, cnt = 0, pos = 0;
  while (cnt < N-1) {
    if (V[pos % N] == -1) {
      ++pos;
      continue;
    }
    if (tick == k) {
      tick = 0;
      if (V[pos % N] == 13)
        return false;
      V[pos % N] = -1;
      ++cnt;
    }
    ++pos; ++tick;
    /*
    for (int i : V)
      cout << i << ' ';
    cout << '\n';
    */
  }
  return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  while (cin >> N) {
    if (N == 0)
      break;
    int pos = 1;
    while (!check(pos))
      ++pos;
    cout << pos << '\n';
  }
return 0;}

