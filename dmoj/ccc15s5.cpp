#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int N, M, A[3001], B[101];
int dp[3001][2][101][101];

int solve(int pos, int take, int l, int r){
	int ret = dp[pos][take][l][r];
	if (ret != -1) return ret;
	else ret = 0;
	if (pos < N){
		//take this pie
		if (!take) ret = max(ret, solve(pos+1,1,l,r) + A[pos]);
		//skip this pie
		ret = max(ret, solve(pos+1,0,l,r));
		//if last pie was taken, put in spare and take this
		if (take && l <= r) ret = max(ret, solve(pos+1,1,l+1,r) + A[pos]);
		//take a spare pie
		if (!take && l <= r) ret = max(ret, solve(pos,1,l,r-1) + B[r]);
	}
	//if we are at the end of the line and spare pies are left
	else if (l <= r){
		//put in separator
		if (take) ret = max(ret, solve(pos,0,l+1,r));
		//else, take a spare
		else ret = max(ret, solve(pos,1,l,r-1) + B[r]);
	}
	dp[pos][take][l][r] = ret;
	return ret;
}

int main(){
	memset(dp,-1,sizeof(dp));
	scanf("%d",&N);
	for (int i = 0; i < N; ++i) scanf("%d",A+i);
	scanf("%d",&M);
	for (int i = 0; i < M; ++i) scanf("%d",B+i);
	sort(B,B+M);
	printf("%d %d\n",N,M);
	printf("%d\n",solve(0,0,0,M-1));
return 0;}
