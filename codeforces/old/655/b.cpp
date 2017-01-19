#include <bits/stdc++.h>
using namespace std;

int N, K, A[100002], B[100002];

void add(int i) {
  while (i < 100002){
    ++B[i];
    i += (i & -i);
  }
}

int sum(int i) {
  int ret = 0;
  while (i > 0) {
    ret += B[i];
    i -= (i & -i);
  }
  return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> N >> K;
  for (int i = 1; i <= N; ++i)
    A[i] = i;
  for (int i = 1; i <= min(K, N/2); ++i)
    swap(A[i], A[N-i+1]);
  /*
  for (int i = 1; i <= N; ++i)
    cout << A[i] << ' ';
  cout << '\n';
  */
  long long ans = 0;
  for (int i = N; i >= 1; --i) {
    //cout << A[i] << ' ' << sum(A[i]) << '\n';
    ans += sum(A[i]);
    add(A[i]);
  }
  cout << ans << '\n';
  return 0;
return 0;}

