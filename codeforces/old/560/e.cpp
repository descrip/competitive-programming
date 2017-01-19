#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

long long amod(long long a, long long b){
	return (a%b+b) % b;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int w, h, n; cin >> h >> w >> n;
	static long long dp[2000], ncr[200001][100001];
	ncr[0][0] = 1;
	for (int i = 1; i <= 200000; ++i){
		ncr[i][0] = 1;
		for (int j = 1; j <= i; ++j)
			ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j]) % MOD;
	}
	static pair<int,int> pt[2000];
	for (int i = 0; i < n; ++i)
		cin >> pt[i].second >> pt[i].first;
	sort(pt,pt+n);
	long long ans = ncr[200000][100000];
	for (int i = 0; i < n; ++i){
		dp[i] += ncr[pt[i].first+pt[i].second-2][pt[i].first-1];
		for (int j = 0; j < n; ++j){
			if (dp[j] < 0)
				//MINUS ONE?
				dp[j] += ncr[pt[j].first+pt[j].second-pt[i].first-pt[i].second][pt[j].first-pt[i].first];
			else
				dp[j] -= ncr[pt[j].first+pt[j].second-pt[i].first-pt[i].second][pt[j].first-pt[i].first];
			dp[j] = amod(dp[j],MOD);
		}
		ans -= dp[i] * ncr[w-pt[i].first+h-pt[i].second][w-pt[i].first];
		ans = amod(ans,MOD);
	}
	cout << ans << '\n';
return 0;}
