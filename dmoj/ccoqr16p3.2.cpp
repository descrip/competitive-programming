#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
const int MAXM = (1e5)+3;
ll N, M, ans = 0;
pair<ll, ll> A[MAXM], last;

ll pyra(ll r) {
  if (!(1 <= r && r <= N)) return 0LL;
  else return (1 + N-r+1) * (N-r+1) / 2;
}

pair<ll, ll> inter(const pair<ll, ll> &a, const pair<ll, ll> &b) {
  return {b.se + a.fi - a.se, b.se};
}

bool ssort(const pair<ll, ll> &a, const pair<ll, ll> &b) {
  if (a.se == b.se)
    return a.fi > b.fi;
  return a.se < b.se;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> N >> M;
  for (int i = 0; i < M; ++i)
    cin >> A[i].fi >> A[i].se;
  sort(A, A+M, ssort);
  last = A[0];
  ans = pyra(A[0].fi);
  for (int i = 1; i < M; ++i) {
    ll C = A[i].fi - last.fi;
    if (last.se <= A[i].se && A[i].se <= last.se+C)
      continue;
    else {
      ans += pyra(A[i].fi) - pyra(inter(last, A[i]).fi);
      last = A[i];
    }
  }
  cout << ans << '\n';
return 0;}

