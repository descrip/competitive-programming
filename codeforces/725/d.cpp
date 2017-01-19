#include <bits/stdc++.h>
using namespace std;

struct diffcomp {
    bool operator() (const pair<long long, long long> &a, const pair<long long, long long> &b) {
        return -(a.first - a.second) < -(b.first - b.second);
    }
};

int N, ans;
long long T, W;
multiset<pair<long long, long long>, diffcomp> before;
vector<pair<long long, long long>> after;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> N >> T >> W;
    for (int i = 0; i < N-1; ++i) {
        long long x, y; cin >> x >> y;
        if (x > T)
            before.insert({x, y});
        else
            after.push_back({x, y});
    }
    sort(after.begin(), after.end());
    ans = before.size();

    //for (int z = 0; z < 5; ++z) {
    while (T >= 0) {
        ans = min(ans, (int)before.size());

        if (before.empty())
            break;

        auto it = before.begin();
        auto p = *it;
        before.erase(it);

        //cout << T << ' ' << p.second - p.first << '\n';

        T -= (p.second - p.first) + 1;
        while (!after.empty() && after.back().first > T) {
            before.insert(after.back());
            after.pop_back();
        }
    }

    cout << ans+1 << '\n';

	return 0;
}

