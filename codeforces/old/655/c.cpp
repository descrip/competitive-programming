#include <bits/stdc++.h>
using namespace std;

int N, K;
bool A[100002];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    char c; cin >> c;
    A[i] = (c == '1');
  }
  int left = 0, curr = 0, mid = 0;
  int ans = 0xfffffff;
  while (A[left])
    ++left;
  for (int right = left; right < N; ++right) {
    if (A[right])
      continue;
    ++curr;
    if (curr > K+1) {
      --curr;
      ++left;
      while (A[left])
        ++left;
    }
    while (true) {
      int next = mid+1;
      while (A[next] && next <= right)
        ++next;
      if (left <= next && next <= right && !A[next] &&
          max(next - left, right - next) < max(mid - left, right - mid)) {
        //cout << mid << ' ' << next << ' ' << A[next] << '\n';
        mid = next;
      }
      else
        break;
    }
    if (curr >= K+1) {
      //cout << left << ' ' << mid << ' ' << right << ' ' << curr << '\n';
      ans = min(ans, max(mid - left, right - mid));
    }
  }
  cout << ans << '\n';
return 0;}

