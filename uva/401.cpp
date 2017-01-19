#include <bits/stdc++.h>
using namespace std;

char m[3000];

string mirror(string s) {
  reverse(s.begin(), s.end());
  for (int i = 0; i < s.size(); ++i)
    if (m[s[i]] != '\0')
      s[i] = m[s[i]];
    else
      return ".....";
  return s;
}

string rev(string s){
  reverse(s.begin(), s.end());
  return s;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  m['A']='A';
  m['E']='3';
  m['H']='H';
  m['I']='I';
  m['J']='L';
  m['L']='J';
  m['M']='M';
  m['O']='O';
  m['S']='2';
  m['T']='T';
  m['U']='U';
  m['V']='V';
  m['W']='W';
  m['X']='X';
  m['Y']='Y';
  m['Z']='5';
  m['1']='1';
  m['2']='S';
  m['3']='E';
  m['5']='Z';
  m['8']='8';
  string S;
  while (cin >> S) {
    bool palin = (rev(S) == S),
         mirr = (mirror(S) == S);
    //cout << mirror(S) << '\n';
    //break;
    cout << S << " -- ";
    if (palin && mirr)
      cout << "is a mirrored palindrome.\n";
    else if (palin)
      cout << "is a regular palindrome.\n";
    else if (mirr)
      cout << "is a mirrored string.\n";
    else
      cout << "is not a palindrome.\n";
    cout << '\n';
  }
return 0;}

