#include <bits/stdc++.h>
using namespace std;

int T;
vector<pair<string, int>> V;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        V.clear();
        int M = 0;
        for (int i = 0; i < 10; ++i) {
            string S; int K; cin >> S >> K;
            V.push_back({S, K});
            M = max(M, K);
        }
        cout << "Case #" << t << ":\n";
        for (int i = 0; i < 10; ++i)
            if (V[i].second == M)
                cout << V[i].first << '\n';
    }
	return 0;
}

