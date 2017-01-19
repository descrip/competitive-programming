#include <bits/stdc++.h>
using namespace std;

int T;
string S;
vector<int> V = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> T;
    getline(cin, S);
    for (int t = 1; t <= T; ++t) {
        getline(cin, S);
        int ans = 0;
        for (char c : S)
            if (c == ' ') ++ans;
            else ans += V[c-'a'];
        cout << "Case #" << t << ": " << ans << '\n';
    }
	return 0;
}

