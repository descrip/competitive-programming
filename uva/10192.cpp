#include <bits/stdc++.h>
using namespace std;

string s, t;
int n1, n2, dp[105][105];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    for (int x = 1; true; ++x) {
        getline(cin, s);
        if (s == "#")
            break;
        getline(cin, t);
        n1 = s.size(); n2 = t.size();
        fill_n(dp[0], 105*105, 0);
        for (int i = 1; i <= n1; ++i)
            for (int j = 1; j <= n2; ++j)
                dp[i][j] = max(dp[i-1][j-1] + (s[i-1] == t[j-1]), max(dp[i-1][j], dp[i][j-1]));
        cout << "Case #" << x << ": you can visit at most " << dp[n1][n2] << " cities.\n";
    }
	return 0;
}

