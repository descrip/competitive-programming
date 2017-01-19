#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1003, MAXP = 13;
#define fi first
#define se second

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, P; cin >> N >> P;
	static int A[MAXN][MAXP];
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= P; ++j)
			cin >> A[i][j];
	for (int j = 1; j <= P; ++j)
		for (int i = 1; i <= N; ++i)
			A[i][j] += A[i-1][j];
	static int curr[MAXP];
	static bool win[MAXN][MAXN];
	for (int r = 1; r <= N; ++r)
		for (int l = r; l >= 1; --l){
			for (int k = 1; k <= P; ++k)
				curr[k] = A[r][k] - A[l-1][k];
			int m = 0;
			for (int k = 2; k <= P; ++k)
				m = max(m, curr[k]);
			if (m < curr[1])
				win[l][r] = true;
		}
	static map<pair<int,int>, int> dp[MAXN];
	dp[0][make_pair(0, 0)] = 0;
	for (int i = 1; i <= N; ++i)
		for (int j = 0; j < i; ++j)
			for (pair<pair<int,int>, int> k : dp[j]){
				pair<int, int> tmp = {k.fi.fi + win[j+1][i], k.fi.se + 1};
				if (dp[i].count(tmp) == 0)
					dp[i][tmp] = k.se + i-j-1;
				else
					dp[i][tmp] = min(dp[i][tmp], k.se + i-j-1);
			}
	/*
	for (int i = 1; i <= N; ++i){
		cout << i << '\n';
		for (pair<pair<int, int>, int> p : dp[i])
			cout << p.fi.fi << ' ' << p.fi.se << ' ' << p.se << '\n';
	}
	*/
	int ans = 0xfffffff;
	for (pair<pair<int,int>, int> i : dp[N])
		if (i.fi.fi >= floor(i.fi.se/2.0) + 1)
			ans = min(ans, i.se);
	cout << (ans == 0xfffffff ? -1 : ans) << '\n';
return 0;}
