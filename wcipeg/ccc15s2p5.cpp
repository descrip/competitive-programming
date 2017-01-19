#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, D; cin >> N >> D;
	static double dp[100][13][13][13][13];
	fill_n(dp[0][0][0][0], 100*13*13*13*13, -1);
	static int lim[4];
	for (int i = 0; i < 4; ++i)
		if (i > D-1)
			lim[i] = 12;

	int time, pit; cin >> time >> pit;
	--pit;
	for (int i2 = 0; i2 < 12; ++i2)
	for (int j2 = min(max(i2+1,lim[1]),12); j2 < max(12,lim[1]+1); ++j2)
	for (int k2 = min(max(j2+1,lim[2]),12); k2 < max(12,lim[2]+1); ++k2)
	for (int l2 = min(max(k2+1,lim[3]),12); l2 < max(12,lim[3]+1); ++l2)
		if (i2 == pit || j2 == pit || k2 == pit || l2 == pit)
			dp[0][i2][j2][k2][l2] = 0xfffffff;

	int last = time;
	for (int note = 1; note < N; ++note){
		cin >> time >> pit;
		--pit;
		for (int i1 = 0; i1 < 12; ++i1)
		for (int j1 = min(max(i1+1,lim[1]),12); j1 < max(12,lim[1]+1); ++j1)
		for (int k1 = min(max(j1+1,lim[2]),12); k1 < max(12,lim[2]+1); ++k1)
		for (int l1 = min(max(k1+1,lim[3]),12); l1 < max(12,lim[3]+1); ++l1){
			for (int i2 = 0; i2 < 12; ++i2)
			for (int j2 = min(max(i2+1,lim[1]),12); j2 < max(12,lim[1]+1); ++j2)
			for (int k2 = min(max(j2+1,lim[2]),12); k2 < max(12,lim[2]+1); ++k2)
			for (int l2 = min(max(k2+1,lim[3]),12); l2 < max(12,lim[3]+1); ++l2){
				if (dp[note-1][i1][j1][k1][l1] != -1 && (i2 == pit || j2 == pit || k2 == pit || l2 == pit)){
					int change = (i1 != i2) + (j1 != j2) + (k1 != k2) + (l1 != l2);
					dp[note][i2][j2][k2][l2] = max(dp[note][i2][j2][k2][l2],
						min(dp[note-1][i1][j1][k1][l1], (change == 0 ? 0xfffffff : (double)(time-last)/change)));
				}
			}
		}
		last = time;
	}

	double ans = 0;
	for (int i1 = 0; i1 < 12; ++i1)
	for (int j1 = min(max(i1+1,lim[1]),12); j1 < max(12,lim[1]+1); ++j1)
	for (int k1 = min(max(j1+1,lim[2]),12); k1 < max(12,lim[2]+1); ++k1)
	for (int l1 = min(max(k1+1,lim[3]),12); l1 < max(12,lim[3]+1); ++l1)
		ans = max(ans, dp[N-1][i1][j1][k1][l1]);
	cout << fixed << setprecision(2) << round((ans == 0xfffffff ? 0 : ans)*100)/100 << '\n';
return 0;}

