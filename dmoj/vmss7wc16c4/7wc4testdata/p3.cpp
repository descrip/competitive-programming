#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int D, I, R; cin >> D >> I >> R;
	string S, T; cin >> S >> T;
	static int dp[1010][1010];
	for (int i = 0; i <= S.size(); ++i)
		for (int j = 0; j <= T.size(); ++j){
			if (i == 0)
				dp[i][j] = j * I;
			else if (j == 0)
				dp[i][j] = i * D;
			else
				dp[i][j] = min(dp[i][j-1] + I, min(dp[i-1][j] + D, dp[i-1][j-1] + R * (S[i-1] != T[j-1])));
		}
	cout << dp[S.size()][T.size()] << '\n';
return 0;}

