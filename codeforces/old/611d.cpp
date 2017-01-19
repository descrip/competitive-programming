#include <bits/stdc++.h>
using namespace std;

const int MOD = (1e9) + 7;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; string S; cin >> N >> S;
	static int dp[5010][5010], ps[5010][5010], ls[5010][5010];
	fill_n(ls[0], 5010*5010, 0xfffffff);
	for (int i = N-1; i >= 0; --i)
		for (int j = N-1; j >= 0; --j){
			if (S[i] != S[j])
				ls[i][j] = 0;
			else
				ls[i][j] = ls[i+1][j+1] + 1;
		}
	dp[1][1] = dp[0][0] = ps[1][1] = ps[0][0] = 1;
	for (int pos = 1; pos <= N; ++pos){
		for (int len = 1; len <= pos; ++len){
			int k = pos - len*2 + 1, t = ls[k-1][pos-len];
			if (S[pos-len] == '0')
				dp[pos][len] = 0;
			else if (k <= 0)
				dp[pos][len] = ps[pos-len][pos-len];
			else if (t < 0xfffffff && k+t <= pos-len && S[k+t-1] < S[pos-len+t])
				dp[pos][len] = ps[pos-len][len];
			else
				dp[pos][len] = ps[pos-len][len-1];
			//cout << pos << ' ' << len << ' ' << k << ' ' << t << '\n';
			ps[pos][len] = (ps[pos][len-1] + dp[pos][len]) % MOD;
		}
	}

	/*
	for (int y = 0; y <= N; ++y){
		for (int x = 0; x <= N; ++x)
			cout << dp[y][x] << ' ';
		cout << '\n';
	}
	cout << "--------------\n";
	for (int y = 0; y <= N; ++y){
		for (int x = 0; x <= N; ++x)
			cout << ps[y][x] << ' ';
		cout << '\n';
	}
	*/

	cout << ps[N][N] << '\n';
return 0;}

