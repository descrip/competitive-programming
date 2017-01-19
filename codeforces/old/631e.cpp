#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 200005;
ll N, A[MAXN], S[MAXN];

struct line {
  int m, b;
} sta1[MAXN], sta2[MAXN];

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    cin >> A[i];
    S[i] = S[i-1] + A[i] * i;
  }
return 0;}

