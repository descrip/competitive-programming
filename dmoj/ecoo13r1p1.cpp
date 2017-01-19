#include <bits/stdc++.h>
using namespace std;


int main(){
  int tick; cin >> tick; --tick;
  while (true) {
    int tot = 0, cnt = 0;
    bool done = false;
    while (true) {
      string s; cin >> s;
      if (s == "TAKE") {
        tick = (tick + 1) % 999;
        ++tot;
        ++cnt;
      }
      else if (s == "SERVE")
        --cnt;
      else if (s == "CLOSE")
        break;
      else if (s == "EOF") {
        done = true;
        break;
      }
    }
    if (done)
      break;
    cout << tot << ' ' << cnt << ' ' << tick+1 << '\n';
  }
return 0;}
