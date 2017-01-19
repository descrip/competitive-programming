#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	static bool a[101];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i; j < n; ++j){
			for (int k = i; k <= j; ++k)
				a[k] = 1-a[k];
			int cnt = 0;
			for (int k = 0; k < n; ++k)
				if (a[k])
					++cnt;
			ans = max(ans,cnt);
			for (int k = i; k <= j; ++k)
				a[k] = 1-a[k];
		}
	cout << ans << '\n';
return 0;}
