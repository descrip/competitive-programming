#include <bits/stdc++.h>
using namespace std;

int N, M, A[3005], B[105], dp[3005][105][105][2];

int recur(int pos, int l, int r, bool take){
	//cout << l << ' ' << r << ' ' << dp[pos][l][r][take] << '\n';
	if (dp[pos][l][r][take] != -1)
		return dp[pos][l][r][take];
	int ret = 0;
	if (pos < N){
		if (take){
			ret = max(ret, recur(pos+1, l, r, false));
			if (l < r)
				ret = max(ret, recur(pos+1, l+1, r, true) + A[pos]);
		}
		else if (!take){
			ret = max(ret, max(recur(pos+1, l, r, true) + A[pos],
				recur(pos+1, l, r, false)));
			if (l < r)
				ret = max(ret, recur(pos, l, r-1, true) + B[r-1]);
		}
	}
	else if (pos == N && l < r){
		if (take)
			ret = max(ret, recur(pos, l+1, r, false));
		else
			ret = max(ret, recur(pos, l, r-1, true) + B[r-1]);
	}
	return dp[pos][l][r][take] = ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	cin >> M;
	for (int i = 0; i < M; ++i)
		cin >> B[i];
	sort(B, B+M);
	fill_n(dp[0][0][0], 3005*105*105*2, -1);
	cout << recur(0, 0, M, false) << '\n';
return 0;}

