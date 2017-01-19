#include <fstream>
#include <iostream>
using namespace std;

int N, K;
long long dp[501][501];
pair<int,int> A[501];

inline int manhat(int x1, int y1, int x2, int y2){
	return abs(x1 - x2) + abs(y1 - y2);
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	ifstream fin ("marathon.in");
	fin >> N >> K;
	for (int i = 0; i < N; ++i)
		fin >> A[i].first >> A[i].second;
	fill_n(dp[0],501*501,0xFFFFFFF);
	dp[0][0] = 0;
	for (int i = 1; i < N; ++i)
		for (int j = i-1; j >= 0; --j)
			for (int k = 0; k <= K; ++k)
				if (k-(i-j-1) >= 0)
					dp[i][k] = min(dp[i][k],dp[j][k-(i-j-1)]+
					manhat(A[i].first,A[i].second,A[j].first,A[j].second));
	long long ans = 0xFFFFFFF;
	for (int k = 0; k <= K; ++k)
		ans = min(ans,dp[N-1][k]);
	ofstream fout ("marathon.out");
	fout << ans << '\n';
	fout.close();
	fin.close();
return 0;}
