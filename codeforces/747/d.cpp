#include <bits/stdc++.h>
using namespace std;

int n, k, t[200005], cnt = 0;
vector<pair<int, int>> v;
vector<int> w;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
        if (t[i] < 0)
            ++cnt;
    }
    if (cnt > k) {
        cout << "-1\n";
        return 0;
    }
    k -= cnt;
    for (int i = 0; i < n; ++i) {
        if (t[i] < 0)
            for (int j = i+1; j <= n; ++j)
                if (t[j] >= 0 || j == n) {
                    v.push_back({i, j-1});
                    i = j-1;
                    break;
                }
    }
    /*
    for (auto p : v)
        cout << p.first << ' ' << p.second << '\n';
        */
    for (int i = 1; i < v.size(); ++i)
        w.push_back(v[i].first - v[i-1].second - 1);
    int ans = 0;
    if (!v.empty())
        ans = v.size() * 2 - 1 + (v.back().second != n-1);
    bool tick = false;
    sort(w.begin(), w.end());
    for (int i : w)
        if (i <= k) {
            ans -= 2;
            k -= i;
        }
        else break;
    if (!v.empty()) {
    int x = v.back().second;
        if (x != n-1 && (n-x-1) <= k)
            ans--;
    }
    cout << ans << '\n';
	return 0;
}

