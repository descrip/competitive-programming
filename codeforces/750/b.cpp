#include <bits/stdc++.h>
using namespace std;

int N, Y = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int t; string S;
        cin >> t >> S;
        if ((Y == 0 && S[0] != 'S') || (Y == 20000 && S[0] != 'N')) {
            cout << "NO\n"; return 0;
        }
        if (S[0] == 'N') Y -= t;
        else if (S[0] == 'S') Y += t;
        if (Y < 0 || Y > 20000) {
            cout << "NO\n"; return 0;
        }
    }
    cout << (Y != 0 ? "NO" : "YES") << '\n';
	return 0;
}

