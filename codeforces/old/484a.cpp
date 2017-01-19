#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; ++i){
		ll l, r; cin >> l >> r;
		ll a = 1;
		while (a-1 <= r)
			a *= 2;
		a /= 2;
		if (l <= a-1 && a-1 <= r)
			cout << a-1 << '\n';
		else{
			int ans = l;
			for (int j = l+1; j <= r; ++j)
				if (__builtin_popcount(j) > __builtin_popcount(ans))
					ans = j;
			cout << ans << '\n';
		}
	}
return 0;}
