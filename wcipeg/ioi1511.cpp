#include <bits/stdc++.h>
using namespace std;

const int NMAX = 10e7+4;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k, l; cin >> n >> k >> l;
	static int a[NMAX];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	static long long cw[NMAX], ccw[NMAX];
	for (int i = 1; i <= n; ++i)
		cw[i] = (i-k >= 1 ? cw[i-k] : 0) + 2*a[i-1];
	for (int i = n-1; i >= 0; --i)
		ccw[i] = (i+k < n ? ccw[i+k] : 0) + 2*(l-a[i]);
	/*
	cout << cw[0] << ' ' << cw[1] << ' ' << cw[2] << ' ' << cw[3] << '\n';
	cout << ccw[0] << ' ' << ccw[1] << ' ' << ccw[2] << ' ' << ccw[3] << '\n';
	*/
	long long ans = (1LL << 60LL);
	for (int i = 0; i <= n; ++i)
		ans = min(ans, cw[i] + ccw[i]);
	for (int i = 0; i <= n; ++i){
		int j = min(n+1, i+k);
		ans = min(ans, cw[i] + ccw[j] + l);
	}
	if (k >= n)
		ans = min(ans, (long long)l);
	cout << ans << '\n';
return 0;}
