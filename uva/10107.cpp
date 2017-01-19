#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  //Lazy solution, O(N^2) makes it through because it's an old problem
  //I wonder if today's OJ problems will become useless in the future if we invent incredibly fast computers
  //It's already happened kinda
  vector<int> V;
  int X;
  while (cin >> X) {
    V.push_back(X);
    sort(V.begin(), V.end());
    int N = V.size();
    /*
    for (int i : V)
      cout << i << ' ';
    cout << '\n';
    */
    if (N % 2 == 0)
      cout << V[N/2-1] + (V[N/2] - V[N/2-1])/2 << '\n';
    else
      cout << V[N/2] << '\n';
  }
return 0;}

