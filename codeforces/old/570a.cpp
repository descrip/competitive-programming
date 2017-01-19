#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	static int cnt[101];
	for (int i = 0; i < m; ++i){
		int best = 0, ans = 1;
		for (int j = 1; j <= n; ++j){
			int a; cin >> a;
			if (a > best){
				best = a;
				ans = j;
			}
		}
		++cnt[ans];
	}
	int best = 0, ans = 1;
	for (int i = 1; i <= n; ++i)
		if (cnt[i] > best){
			ans = i;
			best = cnt[i];
		}
	cout << ans << '\n';
return 0;}

