#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	vector<int> A (N);
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	static int dp[405][405];
	int ans = 0;
	for (int i = 0; i < N; ++i){
		dp[i][i] = A[i];
		ans = max(ans, dp[i][i]);
	}
	for (int i = 0; i < N-1; ++i)
		if (A[i] == A[i+1]){
			dp[i][i+1] = A[i] + A[i+1];
			ans = max(ans, dp[i][i+1]);
		}
	for (int i = 0; i < N-2; ++i)
		if (A[i] == A[i+2]){
			dp[i][i+2] = A[i] + A[i+1] + A[i+2];
			ans = max(ans, dp[i][i+2]);
		}
	for (int r = 0; r < N; ++r)
		for (int l = r-1; l >= 0; --l){
			if (dp[l][r] == 0){
				for (int i = l; i < r; ++i){
					for (int j = i+2; j <= r; ++j)
						if (dp[l][i] != 0 && dp[j][r] != 0 && dp[i+1][j-1] != 0 && dp[l][i] == dp[j][r])
							dp[l][r] = dp[l][i] + dp[j][r] + dp[i+1][j-1];
					if (dp[l][i] != 0 && dp[i+1][r] != 0 && dp[l][i] == dp[i+1][r])
						dp[l][r] = dp[l][i] + dp[i+1][r];
				}
			}
			ans = max(ans, dp[l][r]);
		}
	//cout << dp[4][5] << ' ' << dp[3][6] << ' ' << dp[3][3] << ' ' << dp[6][6] << '\n';
	//cout << dp[1][6] << ' ' << dp[1][2] << ' ' << dp[3][6] << '\n';
	cout << ans << '\n';
return 0;}

