#include <bits/stdc++.h>
using namespace std;

int gao(string s, string t) {
  static bool vis[10][10];
  fill_n(vis[0], 10*10, false);
  priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
  pq.push({0, s});
  while (!pq.empty()) {
    pair<int, string> curr = pq.top(); pq.pop();
    if (curr.second == t)
      return curr.first;
    pair<int, int> pos = {curr.second[0]-'a', curr.second[1]-'1'};
    if (vis[pos.first][pos.second])
      continue;
    vis[pos.first][pos.second] = true;
    for (int i = -2; i <= 2; i+=4)
      for (int j = -1; j <= 1; j+=2)
        if (0 <= pos.first+i && pos.first+i < 8 && 
            0 <= pos.second+j && pos.second+j < 8)
          pq.push({curr.first+1, string("") + (char)('a'+pos.first+i) + (char)('1'+pos.second+j)});
    for (int i = -1; i <= 1; i+=2)
      for (int j = -2; j <= 2; j+=4)
        if (0 <= pos.first+i && pos.first+i < 8 && 
            0 <= pos.second+j && pos.second+j < 8)
          pq.push({curr.first+1, string("") + (char)('a'+pos.first+i) + (char)('1'+pos.second+j)});
  }
  return -1;    //Should never happen.
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s, t;
  while (cin >> s >> t)
    cout << "To get from " << s << " to " << t << " takes " << gao(s, t) << " knight moves.\n";
return 0;}

