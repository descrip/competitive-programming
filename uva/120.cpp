#include <bits/stdc++.h>
using namespace std;

vector<int> v, w;

void flip(int x) {
  for (int i = x; i < ceil((v.size()-1+x)/2.0); ++i)
    swap(v[i], v[v.size()-(i-x)-1]);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s;
  while (getline(cin, s)) {
    v.clear();
    stringstream ss (s);
    int x; 
    while (ss >> x)
      v.push_back(x);

    for (int i = 0; i < v.size(); ++i)
      cout << v[i] << " \n"[i==v.size()-1];

    reverse(v.begin(), v.end());
    w = v;
    sort(w.begin(), w.end(), greater<int>());
    int pos = 0;

    /*
    for (int i : v)
      cout << i << ' ';
    cout << '\n';
    flip(1);
    for (int i : v)
      cout << i << ' ';
    cout << '\n';
    */

    while (v != w) {
      int tmp = find(v.begin(), v.end(), w[pos]) - v.begin();
      cout << tmp+1 << ' ';
      flip(tmp);
      if (v == w)
        break;
      flip(pos);
      cout << pos+1 << ' ';
      ++pos;
    }
    cout << "0\n";
  }
return 0;}

