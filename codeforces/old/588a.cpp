#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	static int a[100000], p[100000];
	for (int i = 0; i < n; ++i)
		cin >> a[i] >> p[i];
	int s = p[0];
	for (int i = 0; i < n; ++i){
		s = min(s, p[i]);
		p[i] = s;
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i)
		ans += a[i] * p[i];
	cout << ans << '\n';
return 0;}
