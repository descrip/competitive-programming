#include <bits/stdc++.h>
using namespace std;

#define NUM_TESTS 5
#define DEBUG false
#define DEBUG1 false
int A[9][9], Z[8][3][3], B[3][3], ans;
string comp = 
  " 4 9 2 3 5 7 8 1 6 "
  " 8 1 6 3 5 7 4 9 2 "
  " 6 1 8 7 5 3 2 9 4 "
  " 4 3 8 9 5 1 2 7 6 "
  " 2 7 6 9 5 1 4 3 8 "
  " 2 9 4 7 5 3 6 1 8 "
  " 6 7 2 1 5 9 8 3 4 "
  " 8 3 4 1 5 9 6 7 2 ";


int solve(int e) {
  ans = 0;

  //find new
  static set<int> todo;
  for (int i = 1; i <= 9; ++i)
    todo.insert(i);
  for (int i = 0; i < 9; ++i)
    todo.erase(B[i/3][i%3]);

  if (DEBUG)
    cout << 0 << '\n';

  if (DEBUG1) {
    for (int y = 0; y < 3; ++y) {
      for (int x = 0; x < 3; ++x)
        cout << B[y][x];
      cout << '\n';
    }
    cout << "todo: ";
    for (int i : todo)
      cout << i << ' ';
    cout << '\n';
  }

  //move old into new
  while (true) {
    bool did = false;
    for (int i = 0; i < 9 && !did; ++i)
      if (B[i/3][i%3] != Z[e][i/3][i%3])
        for (int j = 0; j < 9; ++j)
          if (Z[e][j/3][j%3] == B[i/3][i%3]) {
            did = true;
            swap(B[i/3][i%3], B[j/3][j%3]);
            ++ans;
            break;
          }
    if (!did)
      break;
  }

  if (DEBUG)
    cout << 1 << '\n';

  if (DEBUG1) {
    for (int y = 0; y < 3; ++y) {
      for (int x = 0; x < 3; ++x)
        cout << B[y][x];
      cout << '\n';
    }
    cout << "todo: ";
    for (int i : todo)
      cout << i << ' ';
    cout << '\n';
  }

  return ans+todo.size();
}

int solve(int x, int y) {
  int ret = 0xfffffff;
  for (int i = 0; i < 8; ++i) {
    for (int y1 = y; y1 < y+3; ++y1)
      for (int x1 = x; x1 < x+3; ++x1)
        B[y1-y][x1-x] = A[y1][x1];
    ret = min(ret, solve(i));
  }
  return ret;
}

int main() {
  //ios_base::sync_with_stdio(0); cin.tie(0);
  stringstream sscomp (comp);
  for (int i = 0; i < 8; ++i)
    for (int y = 0; y < 3; ++y)
      for (int x = 0; x < 3; ++x)
        sscomp >> Z[i][y][x];

  for (int t = 0; t < NUM_TESTS; ++t) {
    for (int i = 0; i < 81; ++i) {
      char c; cin >> c;
      if (c == '\r')
        cin >> c;
      A[i/9][i%9] = c-'0';
    }
    for (int y = 0; y < 9; y+=3) {
      for (int x = 0; x < 9; x+=3)
        cout << solve(x, y);
      cout << '\n';
    }
    cout << "---\n";
  }
return 0;}
