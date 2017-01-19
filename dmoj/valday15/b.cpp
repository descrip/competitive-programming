#include <vector>
#include <cstdio>
using namespace std;

#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main(){
	int c,m;
	scanf("%d %d",&c,&m);
	vector<int> w (c), v(c);
	for (int i = 0; i < c; ++i)
		scanf("%d %d",&v[i],&w[i]);
	vector<vector<int>> dp (c+1, vector<int> (m+1));
	for (int i = 0; i <= c; ++i){
		for (int j = 0; j <= m; ++j){
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (w[i-1] <= j)
				dp[i][j] = max(v[i-1] + dp[i-1][j-w[i-1]], dp[i-1][j]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	printf("%d\n",dp[c][m]);
	return 0;
}
