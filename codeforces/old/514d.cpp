#include <vector>
#include <cstdio>
using namespace std;

#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

bool lessThan(const vector<int> &a, const vector<int> b){
	for (int i = 0; i < a.size(); ++i)
		if (b[i] > a[i])
			return false;
	return true;
}

int sumDp(const vector<int> &a){
	int ret = 0;
	for (int i = 0; i < a.size(); ++i)
		ret += a[i];
	return ret;
}

vector<int> maxRange(const vector<vector<int>> &v, int a, int b){
	vector<int> ret (v[0].size());
	for (int i = a; i < b; ++i)
		for (int j = 0; j < ret.size(); ++j)
			ret[j] = max(ret[j],v[i][j]);
	return ret;
}

int main(){
	int n, m;
	ll k;
	scanf("%d %d %lld",&n,&m,&k);
	vector<vector<int>> r (n, vector<int> (m)), dp (n, vector<int> (m)), len (n);
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j)
			scanf("%d",&r[i][j]);
	}
	dp[0] = r[0];
	len[0] = 1;
	for (int i = 1; i < n; ++i){
		if (lessThan(dp[i-1],dp[i])){
			dp[i] = dp[i-1];
			len[i] = len[i-1] + 1;
		}
		else{
			dp[i] = r[i];
			dp[i] = maxRange(dp,i-1,i+1);
			if (sumDp(dp[i]) <= k){
				len[i] = len[i-1] + 1;
			}
			else{
				for (int j = 1; j <= len[i-1]; ++j){
					auto curr = maxRange(dp,i - len[i-1],i+1);
					if (sumDp(curr) <= k){
						dp[i] = curr;
						len[i] = i-j+1;
						break;
					}
				}
			}
		}
	}
	int best = 0;
	vector<int> ans;
	for (int i = 0; i < n; ++i){
		if (len[i] > best){
			best = len[i];
			ans = dp[i];
		}
	}
	for (int i = 0; i < m-1; ++i)
		printf("%d ",dp[i]);
	printf("%d\n",dp[m-1]);
	return 0;
}
