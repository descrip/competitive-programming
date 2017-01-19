#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;
const ll MAXN = (1e9)+3, MAXM = (1e5)+3;
ll N, M, ans = 0;
pair<ll, ll> A[MAXM];
list<pair<ll, ll>> L;
vector<pair<ll, ll>> ran[2];
bool id = false;

ll pyra(ll r) {
  if (!(1LL <= r && r <= N)) return 0;
  return (1 + N-r+1) * (N-r+1) / 2;
}

pair<ll, ll> inter(pair<ll, ll> a, pair<ll, ll> b) {
  return {b.se + a.fi - a.se, b.se};
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
  /*
  freopen("ccoqr16p3.in", "r", stdin);
  freopen("ccoqr16p3.out", "w", stdout);
  */
  cin >> N >> M;
  for (int i = 0; i < M; ++i)
    cin >> A[i].fi >> A[i].se;
  sort(A, A+M);
  for (int i = 0; i < M; ++i)
    L.push_back(A[i]);

  auto curr = L.begin();
  pair<ll, ll> last;
  while (curr != L.end()) {
    if (curr != L.begin() && curr->fi != last.fi) {
      ll c = curr->fi - last.fi;
      int l = 0, r = 1;
      ran[!id].clear();
      for (; r < ran[id].size(); ++r)
        if (ran[id][r-1].se+c < ran[id][r].fi) {
          ran[!id].push_back({ran[id][l].fi, ran[id][r-1].se+c});
          l = r;
        }
      ran[!id].push_back({ran[id][l].fi, ran[id][r-1].se+c});
      id = !id;
    }
    last = *curr;

    /*
    cout << curr->fi << ' ' << curr->se << '\n';
    for (pair<ll, ll> p : ran[id])
      cout << p.fi << ' ' << p.se << '\n';
    */

    auto it = upper_bound(ran[id].begin(), ran[id].end(),
        make_pair(curr->se, 1000000000000000000LL));
    if (it != ran[id].begin())
      --it;
    if (ran[id].empty() || !(it->fi <= curr->se && curr->se <= it->se)) {
      /*
      if (!ran[id].empty())
        cout << "yes " << it->fi << ' ' << it->se << '\n';
        */
      ran[id].push_back({curr->se, curr->se});
      sort(ran[id].begin(), ran[id].end());
      ++curr;
    }
    else
      curr = L.erase(curr);

    //cout << '\n';
  }

  /*
  for (pair<ll, ll> p : L)
    cout << p.fi << ' ' << p.se << '\n';
    */

  int cnt = 0;
  for (pair<ll, ll> p : L)
    A[cnt++] = {p.se, p.fi};
  M = L.size();
  sort(A, A+M);
  for (int i = 0; i < M; ++i)
    A[i] = {A[i].se, A[i].fi};

  ans = pyra(A[0].fi);
  for (int i = 1; i < M; ++i)
    ans += pyra(A[i].fi) - pyra(inter(A[i-1], A[i]).fi);
  cout << ans << '\n';
return 0;}

