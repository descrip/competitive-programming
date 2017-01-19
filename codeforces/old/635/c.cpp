#include <bits/stdc++.h>
using namespace std;

//TODO: Check zero

long long S, X;
long long dp[50][50];

long long recur(long long pos, long long co){
	if (pos == 50LL)
		return (co == 0LL);
	if (dp[pos][co] != -1LL)
		return dp[pos][co];
	long long ret = 0LL;
	for (int i = 0; i <= 1; ++i)
		for (int j = 0; j <= 1; ++j){
			//cout << (i ^ j) << ' ' << ((i + j + co) & 1) << '\n';
			if ((i ^ j) == (X & (1LL << pos)) >> pos && (S & (1LL << pos)) >> pos == ((i+j+co) & 1LL))
				ret += recur(pos+1LL, (i+j+co) >> 1LL);
		}
	dp[pos][co] = ret;
	//cout << pos << ' ' << co << ' ' << ret << '\n';
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> S >> X;
	fill_n(dp[0], 50*50, -1LL);
	long long ans = recur(0LL, 0LL);
	if ((0LL ^ S) == X)
		ans -= 2;
	cout << ans << '\n';
return 0;}

