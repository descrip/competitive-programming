#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, Kx, Ky;
pair<ll, ll> Kp;
pair<char, pair<ll, ll>> E[500005];
set<pair<int, int>> B;

ll manhat(const pair<ll, ll> &p1, const pair<ll, ll> &p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

ll manhatK(const pair<char, pair<ll, ll>> &p1, const pair<char, pair<ll, ll>> &p2) {
    return manhat(p1.second, Kp) < manhat(p2.second, Kp);
}

pair<int, int> toDiag(const pair<ll, ll> &p, const pair<ll, ll> &z) {
    return {(p.first - z.first) / max(abs(p.first - z.first), 1LL), 
        (p.second - z.second) / max(abs(p.second - z.second), 1LL)};
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> N >> Kx >> Ky;
    Kp = {Kx, Ky};
    for (int i = 0; i < N; ++i) {
        char c; ll x, y; cin >> c >> x >> y;
        E[i] = {c, {x, y}};
    }
    sort(E, E+N, manhatK);
    for (int i = 0; i < N; ++i) {
        char c = E[i].first;
        ll x = E[i].second.first, y = E[i].second.second;
        if (x == Kx || y == Ky) {
            if (c == 'B')
                B.insert(toDiag(E[i].second, Kp));
            else if (B.count(toDiag(E[i].second, Kp)) == 0) {
                cout << "YES\n"; 
                return 0;
            }
        }
        else if (abs(x - Kx) == abs(y - Ky)) {
            if (c == 'R')
                B.insert(toDiag(E[i].second, Kp));
            else if (B.count(toDiag(E[i].second, Kp)) == 0) {
                cout << "YES\n"; 
                return 0;
            }
        }
    }
    cout << "NO\n";
	return 0;
}

