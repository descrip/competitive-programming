#include <bits/stdc++.h>
using namespace std;

int main(){
	ifstream fin ("movie.in");
	int n, l; fin >> n >> l;
	static vector<int> v[20];
	static int len[20];
	for (int i = 0; i < n; ++i){
		int c; fin >> len[i] >> c;
		while (c--){
			int a; fin >> a;
			v[i].push_back(a);
		}
		sort(v[i].begin(),v[i].end());
	}
	static int dp[(1<<20)+1];
	fill(dp,dp+(1<<20)+1,-1);
	dp[0] = 0;
	int ans = 0x7fffffff;
	for (int i = 1; i <= (1<<n); ++i)
		for (int j = 0; j < n; ++j)
			if ((i & (1<<j)) != 0){
				auto it = upper_bound(v[j].begin(),v[j].end(),dp[i ^ (1<<j)]);
				if (it == v[j].begin()) continue;
				--it;
				dp[i] = max(dp[i],(*it)+len[j]);
				if (dp[i] >= l)
					ans = min(ans,__builtin_popcount(i));
			}
	ofstream fout ("movie.out");
	fout << (ans == 0x7fffffff ? -1 : ans) << '\n';
	fin.close();
	fout.close();
return 0;}
