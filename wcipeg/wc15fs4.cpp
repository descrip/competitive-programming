#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1000005;
int N, A[MAXN];

vector<int> calc(int n) {
  vector<int> ret;
  for (int i = 2; i*i <= n; ++i) {
    int cnt = 0;
    while (n % i == 0) {
      n /= i;
      ++cnt;
    }
    if (cnt > 0) {
      ret.push_back(i);
      ret.push_back(cnt);
    }
  }
  if (n != 1) {
    ret.push_back(n);
    ret.push_back(1);
  }
  return ret;
}

int recur(int lo, int hi) {
  if (!(lo < hi))
    return lo;
  int mid = (lo + hi) / 2;
  if (calc(A[mid]) < calc(A[mid+1]))
    return recur(lo, mid);
  else
    return recur(mid+1, hi);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> N;
  for (int i = 1; i <= N; ++i)
    cin >> A[i];
  cout << recur(1, N) << '\n';
return 0;}

