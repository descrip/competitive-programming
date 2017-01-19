#include <vector>
#include <cstdio>
using namespace std;

#define pb push_back
typedef long long ll;
typedef unsigned long long ull;

int main(){
	int n;
	scanf("%d",&n);
	vector<vector<int>> path (n+1, vector<int>());
	for (;;){
		int x, y;
		scanf("%d %d",&x,&y);
		if (x == 0 && y == 0)
			break;
		path[x].pb(y);
	}
	vector<int> dp (n+1,0);
	dp[1] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j : path[i])
			dp[j] += dp[i];
	printf("%d\n",dp[n]);
	return 0;
}
