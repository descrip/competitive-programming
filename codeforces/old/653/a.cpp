#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> T;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int x; cin >> x;
    T.push_back(x);
  }
  sort(T.begin(), T.end());
  unique(T.begin(), T.end());
  for (int i = 1; i < T.size()-1; ++i)
    if (T[i-1] == T[i]-1 && T[i+1] == T[i]+1) {
      cout << "YES\n";
      return 0;
    }
  cout << "NO\n";
return 0;}

