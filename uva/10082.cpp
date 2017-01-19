#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  //Not fun.
  map<char, char> M;
  M['1'] = '`';
  M['2'] = '1';
  M['3'] = '2';
  M['4'] = '3';
  M['5'] = '4';
  M['6'] = '5';
  M['7'] = '6';
  M['8'] = '7';
  M['9'] = '8';
  M['0'] = '9';
  M['-'] = '0';
  M['='] = '-';
  M['W'] = 'Q';
  M['E'] = 'W';
  M['R'] = 'E';
  M['T'] = 'R';
  M['Y'] = 'T';
  M['U'] = 'Y';
  M['I'] = 'U';
  M['O'] = 'I';
  M['P'] = 'O';
  M['['] = 'P';
  M[']'] = '[';
  M['\\'] = ']';
  M['S'] = 'A';
  M['D'] = 'S';
  M['F'] = 'D';
  M['G'] = 'F';
  M['H'] = 'G';
  M['J'] = 'H';
  M['K'] = 'J';
  M['L'] = 'K';
  M[';'] = 'L';
  M['\''] = ';';
  M['X'] = 'Z';
  M['C'] = 'X';
  M['V'] = 'C';
  M['B'] = 'V';
  M['N'] = 'B';
  M['M'] = 'N';
  M[','] = 'M';
  M['.'] = ',';
  M['/'] = '.';
  string S;
  while (getline(cin, S)) {
    for (int i = 0; i < S.size(); ++i)
      if (M.count(S[i]))
        S[i] = M[S[i]];
    cout << S << '\n';
  }
return 0;}

