#include <bits/stdc++.h>
using namespace std;

string S;
int N, T = 1;
vector<int> V;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    while (cin >> S >> N) {
        cout << "Case " << T++ << ":\n";
        V.clear();
        for (int i = 0; i < S.size(); ++i) {
            V.push_back(i);
            for (int j = i+1; j <= S.size(); ++j)
                if (S[i] != S[j] || j == S.size()) {
                    i = j-1;
                    break;
                }
        }
        /*
        for (int i : V)
            cout << i << ' ';
        cout << '\n';
        */
        for (int i = 0; i < N; ++i) {
            int l, r; cin >> l >> r;
            int x = upper_bound(V.begin(), V.end(), l) - V.begin(),
                y = upper_bound(V.begin(), V.end(), r) - V.begin();
            cout << (x == y ? "Yes" : "No") << '\n';
        }
    }
	return 0;
}

