#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	static bool a[500005];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int l = 0, r = 1, ans = 0;
	for (; r <= n; ++r){
		if (r == n || a[r-1] == a[r]){
			//cout << l << ' ' << r << ' ' << a[l] << ' ' << a[r] << '\n';
			ans = max(ans, r-l);
			if (!a[l] && !a[r-1])
				for (int i = l; i < r; ++i)
					a[i] = 0;
			else if (a[l] ^ a[r-1]){
				int cnt = 0;
				for (int i = l; i < r; ++i)
					if (a[i])
						++cnt;
				for (int i = l; i < r; ++i)
					if ((a[r-1] && i >= r-cnt) || (a[l] && i < l+cnt))
						a[i] = 1;
					else
						a[i] = 0;
			}
			else if (a[l] && a[r-1])
				for (int i = l; i < r; ++i)
					a[i] = 1;
			l = r;
		}
	}
	cout << (ans-1)/2 << '\n';
	for (int i = 0; i < n; ++i)
		cout << a[i] << ' ';
	cout << '\n';
return 0;}
