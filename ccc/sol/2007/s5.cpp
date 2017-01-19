#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

#define pb push_back
typedef long long ll;
typedef unsigned long long ull;

int main(){
	int tests;
	scanf("%d",&tests);
	for (int t = 0; t < tests; ++t){
		int n, k, w;
		scanf("%d %d %d",&n,&k,&w);
		vector<int> pins (n), sums(n);
		for (int i = 0; i < n; ++i)
			scanf("%d",&pins[i]);
		sums[0] = pins[0];
		for (int i = 1; i < n; ++i)
			sums[i] = sums[i-1] + pins[i];
		vector<vector<ull>> dp (k+1, vector<ull>(n));
		for (int i = 1; i <= k; ++i){
			for (int j = 0; j < min(w*i,n); ++j){
				dp[i][j] = sums[j];
			}
			for (int j = w*i; j < n; ++j)
				dp[i][j] = max(max(dp[i-1][j],dp[i][j-1]), 
						dp[i-1][j-w] + sums[j] - sums[j-w]);
		}
		/*
		for (int i = 0; i <= k; ++i){
			for (int j = 0; j < n; ++j)
				printf("%03lld ",dp[i][j]);
			printf("\n");
		}
		*/
		printf("%lld\n",dp[k][n-1]);
	}
	return 0;
}
