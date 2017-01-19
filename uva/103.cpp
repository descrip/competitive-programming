#include <bits/stdc++.h>
using namespace std;

int K, N, dp[31];
pair<vector<int>, int> A[31];
string hist[31];

bool canFit(int i, int j) {
    for (int k = 0; k < N; ++k)
        if (A[i].first[k] >= A[j].first[k])
            return false;
    return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    while (cin >> K >> N) {
        for (int i = 0; i < K; ++i) {
            A[i].first.resize(N, 0);
            for (int j = 0; j < N; ++j)
                cin >> A[i].first[j];
            A[i].second = i;
            sort(A[i].first.begin(), A[i].first.end());
        }
        sort(A, A+K);
        fill_n(dp, 31, 1);
        for (int i = 0; i < K; ++i)
            hist[i] = to_string(A[i].second+1);
        int ans = 1;
        string best = "1";
        for (int i = 1; i < K; ++i)
            for (int j = 0; j < i; ++j)
                if (canFit(j, i) && dp[j]+1 > dp[i]) {
                    dp[i] = dp[j]+1;
                    hist[i] = hist[j] + ' ' + to_string(A[i].second+1);
                    if (dp[i] >= ans) {
                        ans = dp[i];
                        best = hist[i];
                    }
                }
        cout << ans << '\n' << best << '\n';
    }
	return 0;
}

