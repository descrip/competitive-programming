#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string S;
  int cnt = 1;
  while (cin >> S) {
    if (S == "*")
      break;
    cout << "Case " << cnt++ << ": " <<
      (S == "Hajj" ? "Hajj-e-Akbar" : "Hajj-e-Asghar") << '\n';
  }
return 0;}

