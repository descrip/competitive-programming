#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  string s;
  vector<int> v;
  set<int> r;
  while (getline(cin, s)) {
    stringstream ss (s);
    v.clear(); r.clear();
    int n, tmp; ss >> n;
    for (int i = 0; i < n; ++i) {
      ss >> tmp;
      v.push_back(tmp);
    }
    if (n == 1) {
      cout << "Jolly\n";
      continue;
    }
    for (int i = 1; i < v.size(); ++i)
      r.insert(abs(v[i] - v[i-1]));
    /*
    for (int i : r)
      cout << i << ' ';
    cout << '\n';
    */
    cout << (*r.begin() == 1 && *r.rbegin() == n-1 && r.size() == n-1 ? "Jolly" : "Not jolly") << '\n';
  }
return 0;}

