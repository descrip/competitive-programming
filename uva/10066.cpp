#include <bits/stdc++.h>
using namespace std;

int n1, n2, a[105], b[105], dp[105][105];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    for (int t = 1; true; ++t) {
        cin >> n1 >> n2;
        if (n1 == 0 && n2 == 0)
            break;
        for (int i = 1; i <= n1; ++i)
            cin >> a[i];
        for (int i = 1; i <= n2; ++i)
            cin >> b[i];
        for (int i = 1; i <= n1; ++i)
            for (int j = 1; j <= n2; ++j)
                dp[i][j] = max(dp[i-1][j-1]+(a[i] == b[j]), max(dp[i-1][j], dp[i][j-1]));
        cout << "Twin Towers #" << t << "\nNumber of Tiles : " << dp[n1][n2] << "\n\n";
    }
	return 0;
}

