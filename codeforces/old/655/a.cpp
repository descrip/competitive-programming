#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
  string s1; cin >> s1;
  string tmp; cin >> tmp;
  reverse(tmp.begin(), tmp.end());
  s1 += tmp;
  string s2; cin >> s2;
  cin >> tmp;
  reverse(tmp.begin(), tmp.end());
  s2 += tmp;
  s1.erase(s1.begin() + s1.find('X'));
  s2.erase(s2.begin() + s2.find('X'));
  //cout << s1 << ' ' << s2 << '\n';
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      if (s1[j] != s2[(i+j)%3])
        break;
      else if (j == 2){
        cout << "YES\n";
        return 0;
      }
  cout << "NO\n";
return 0;}

