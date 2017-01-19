#include <bits/stdc++.h>
using namespace std;

const long long INF = (1LL<<62);

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	ifstream fin ("guard.in");
	int n, h; fin >> n >> h;
	static int cw[20], ch[20], cs[20];
	for (int i = 0; i < n; ++i)
		fin >> ch[i] >> cw[i] >> cs[i];
	fin.close();
	static long long dp[1<<20], ws[1<<20], hs[1<<20];
	dp[0] = INF;
	long long ans = -INF;
//
	cout << 'w' << ' ';
	for (int i = n-1; i >= 0; --i)
		cout << cw[i] << " \n"[i==0];
	cout << 'h' << ' ';
	for (int i = n-1; i >= 0; --i)
		cout << ch[i] << " \n"[i==0];
	cout << 's' << ' ';
	for (int i = n-1; i >= 0; --i)
		cout << cs[i] << " \n"[i==0];
//
	for (int i = 1; i < (1<<n); ++i){
		dp[i] = -INF;
		for (int j = 0; j < n; ++j)
			if (i & (1<<j)){
				ws[i] += cw[j];
				hs[i] += ch[j];
				dp[i] = max(dp[i], min(dp[i^(1<<j)], cs[j]-ws[i^(1<<j)]));
			}
//
		bitset<4> b(i);
		cout << b << ' ' << dp[i] << '\n';
//
		if (hs[i] >= h)
			ans = max(ans,dp[i]);
	}
	ofstream fout ("guard.out");
	if (ans < 0)
		fout << "Mark is too tall\n";
	else
		fout << ans << '\n';
	fout.close();
return 0;}
