#include <bits/stdc++.h>
using namespace std;

int N;
bool first = true;
vector<string> names;
map<string, int> worth;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  while (cin >> N) {
    names.assign(N, "");
    worth.clear();
    if (!first)
      cout << '\n';
    first = false;
    for (int i = 0; i < N; ++i)
      cin >> names[i];
    for (int i = 0; i < N; ++i) {
      string curr;
      int tot, num;
      cin >> curr >> tot >> num;
      worth[curr] -= tot;
      if (num == 0)
        worth[curr] += tot;
      else {
        for (int j = 0; j < num; ++j) {
          string who; cin >> who;
          worth[who] += tot / num;
        }
        worth[curr] += tot % num;
      }
    }
    for (string s : names)
      cout << s << ' ' << worth[s] << '\n';
  }
return 0;}

