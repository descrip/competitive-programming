#include <bits/stdc++.h>
using namespace std;

int k;
string s, t;
int dp[1002][1002];

int main(){
	while (true){
		cin >> k;
		if (k == 0) break;
		cin >> s >> t;
		memset(dp,-1,sizeof(dp));
		for (int i = 0; i < s.size(); ++i) dp[i][0] = 0;
		for (int i = 0; i < t.size(); ++i) dp[0][i] = 0;
		for (int y = 1; y <= t.size(); ++y){
			for (int x = 1; x <= s.size(); ++x){
				dp[y][x] = max(dp[y-1][x],dp[y][x-1]);
				for (int z = 0; z < min(x,y); ++z){
					if (s[x-z-1] != t[y-z-1]) break;
					if (z >= k-1) dp[y][x] = max(dp[y][x],dp[y-z-1][x-z-1]+z+1);
				}
			}
		}
		cout << max(0,dp[t.size()][s.size()]) << '\n';
	}
return 0;}
