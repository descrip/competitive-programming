#include <iostream>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

struct classcomp {
  bool operator() (const pair<int,int>& lhs, const pair<int, int>& rhs) const {
    if (lhs.first == rhs.first)
      return lhs.second < rhs.second;
    return lhs.first > rhs.first;
  }
};

int N, cnt[5001], last[5001], T[5001], B, ans[5001];
vector<pair<int, int>> Q;
multiset<pair<int, int>, classcomp> all;
//TODO: Lowest index

/*
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first/B != b.first/B)
    return a.first/b < b.first/B;
  return a.second < b.second;
}
*/

int main() {
  //ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> T[i];
    --T[i];
  }
  /*
  for (int i = 0; i < N; ++i)
    for (int j = i+1; j < N; ++j)
      Q.push_back({i, j});
  sort(Q.begin(), Q.end(), cmp);
  */
  for (int len = 1; len <= N; ++len) {
    ++last[T[len-1]];
    fill_n(cnt, N, 0);
    all.clear();
    for (int i = 0; i < N; ++i) {
      cnt[i] = last[i];
      all.insert({cnt[i], i});
    }
    for (int i = 0; i <= N-len; ++i) {
      ++ans[all.begin()->second];

      all.erase(all.find(make_pair(cnt[T[i]], T[i])));
      --cnt[T[i]];
      all.insert({cnt[T[i]], T[i]});

      if (i+len < N) {
        all.erase(all.find({cnt[T[i+len]], T[i+len]}));
        ++cnt[T[i+len]];
        all.insert({cnt[T[i+len]], T[i+len]});
      }

      /*
      cout << i << ' ' << len << ' ' << T[i] << '\n';
      for (auto p : all)
        cout << p.first << ' ' << p.second << '\n';
      cout << '\n';
      */
    }
  }
  for (int i = 0; i < N; ++i)
    cout << ans[i] << ' ';
  cout << '\n';
return 0;}

