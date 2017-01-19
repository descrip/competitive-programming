#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
#include <set>
#include <queue>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <random>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define inf 2000005000
#define lc(x) x<<1
#define rc(x) x<<1|1
#define m(a,b) (a+b)/2
#define EPS 1e-6
#define PI 3.1415926535897932384
#define For(a,b,c) for(int a = b;a<=c;a++)
#define Rev(a,b,c) for(int a = b;a>=c;a--)
#define pb push_back
#define mp make_pair
#define io cin.sync_with_stdio(0); cin.tie(0);
#define MTRAND mt19937 gen(4)
#define RNG(l,h) gen() % (h - l + 1) + l
using namespace std;
const int MAXN =  100005;

int N, l[MAXN], r[MAXN];
int dp[MAXN], mini[4 * MAXN], maxi[4 * MAXN], seg[4 * MAXN], lazy[4 * MAXN];
pair<int,int> dom[MAXN];

void build(int idx, int tl, int tr) {
      if (tl == tr) {
            mini[idx] = inf;
            maxi[idx] = -inf;
            return;
      }
      int mid = m(tl, tr);
      build(lc(idx), tl, mid);
      build(rc(idx), mid + 1, tr);
      mini[idx] = inf;
      maxi[idx] = -inf;
}
void updatel(int idx, int tl, int tr, int pos, int v) {
      if (tl == tr) {
            mini[idx] = v;
            return;
      }
      int mid = m(tl, tr);
      if (pos <= mid)
            updatel(lc(idx), tl, mid, pos, v);
      else
            updatel(rc(idx), mid + 1, tr, pos, v);
      mini[idx] = min(mini[lc(idx)], mini[rc(idx)]);
}

void updater(int idx, int tl, int tr, int pos, int v) {
      if (tl == tr) {
            maxi[idx] = v;
            return;
      }
      int mid = m(tl, tr);
      if (pos <= mid)
            updater(lc(idx), tl, mid, pos, v);
      else
            updater(rc(idx), mid + 1, tr, pos, v);
      maxi[idx] = max(maxi[lc(idx)], maxi[rc(idx)]);
}

int RMinQ(int idx, int tl, int tr, int l, int r) {
      if (tl == l && tr == r) {
            return mini[idx];
      }
      int mid = m(tl, tr);
      if (r <= mid) return RMinQ(lc(idx), tl, mid, l, r);
      else if (l > mid) return RMinQ(rc(idx), mid + 1, tr, l, r);
      else {
            return min(RMinQ(lc(idx), tl, mid, l, mid),
                       RMinQ(rc(idx), mid + 1, tr, mid + 1, r));
      }
}

int RMaxQ(int idx, int tl, int tr, int l, int r) {
      if (tl == l && tr == r) {
            return maxi[idx];
      }
      int mid = m(tl, tr);
      if (r <= mid) return RMaxQ(lc(idx), tl, mid, l, r);
      else if (l > mid) return RMaxQ(rc(idx), mid + 1, tr, l, r);
      else {
            return max(RMaxQ(lc(idx), tl, mid, l, mid),
                       RMaxQ(rc(idx), mid + 1, tr, mid + 1, r));
      }
}

void build2(int idx, int tl, int tr) {
      seg[idx] = inf;
      lazy[idx] = inf;
      if (tl == tr) {
            return;
      }
      int mid = m(tl, tr);
      build2(lc(idx), tl, mid);
      build2(rc(idx), mid + 1, tr);
}
void update(int idx, int tl, int tr, int l, int r, int v) {
      if (tl == l && tr == r) {
            seg[idx] = min(seg[idx], v);
            lazy[idx] = min(lazy[idx], v);
            return;
      }
      if (lazy[idx] != inf) {
            seg[lc(idx)] = min(seg[lc(idx)], lazy[idx]);
            seg[rc(idx)] = min(seg[rc(idx)], lazy[idx]);
            lazy[lc(idx)] = min(lazy[lc(idx)], lazy[idx]);
            lazy[rc(idx)] = min(lazy[rc(idx)], lazy[idx]);
            lazy[idx] = inf;
      }
      int mid = m(tl, tr);
      if (r <= mid)
            update(lc(idx), tl, mid, l, r, v);
      else if (l > mid)
            update(rc(idx), mid + 1, tr, l, r, v);
      else {
            update(lc(idx), tl, mid, l, mid, v);
            update(rc(idx), mid + 1, tr, mid + 1, r, v);
      }
      seg[idx] = min(seg[lc(idx)], seg[rc(idx)]);
}

int query(int idx, int tl, int tr, int pos) {
      if (tl == tr)
            return seg[idx];
      if (lazy[idx] != inf) {
            seg[lc(idx)] = min(seg[lc(idx)], lazy[idx]);
            seg[rc(idx)] = min(seg[rc(idx)], lazy[idx]);
            lazy[lc(idx)] = min(lazy[lc(idx)], lazy[idx]);
            lazy[rc(idx)] = min(lazy[rc(idx)], lazy[idx]);
            lazy[idx] = inf;
      }
      int mid = m(tl, tr);
      if (pos <= mid)
            return query(lc(idx), tl, mid, pos);
      else return query(rc(idx), mid + 1, tr, pos);
}
int main() { io
      cin >> N ;
      For(i, 1, N) {
            cin >> dom[i].first >> dom[i].second;
            dp[i] = inf;
      }
      sort(dom + 1, dom + 1 + N);
      priority_queue<pair<int, int>, vector<pair<int, int > >, greater<pair<int, int> > > q;
      For(i, 1, N) {
            while (!q.empty() && q.top().first < dom[i].first) {
                  r[q.top().second] = i - 1;
                  q.pop();
            }
            q.push(mp(dom[i].first + dom[i].second, i));
      }
      while (!q.empty()) {
            r[q.top().second] = N;
            q.pop();
      }
      
      priority_queue<pair<int, int> > rq;
      Rev(i, N, 1) {
            while (!rq.empty() && rq.top().first > dom[i].first) {
                  l[rq.top().second] = i + 1;
                  rq.pop();
            }
            rq.push(mp(dom[i].first - dom[i].second, i));
      }
      while (!rq.empty()) {
            l[rq.top().second] = 1;
            rq.pop();
      }
      build(1, 1, N);
      updatel(1, 1, N, 1, 1);
      For(i, 2, N) {
            l[i] = min(l[i], RMinQ(1, 1, N, l[i], i));
            updatel(1, 1, N, i, l[i]);
      }
      updater(1, 1, N, N, N);
      Rev(i, N - 1, 1) {
            r[i] = max(r[i], RMaxQ(1, 1, N, i, r[i]));
            updater(1, 1, N, i, r[i]);
      }
      build2(1, 0, N);
      dp[0] = 0;
      update(1, 0, N, 0, 0, 0);
      For(i, 1, N) {
            dp[i] = min(query(1, 0, N, i), query(1, 0, N, l[i] - 1) + 1);
            update(1, 0, N, i, i, dp[i]);
            update(1, 0, N, i, r[i], dp[i - 1] + 1);
      }
      cout << dp[N] << endl;
}
