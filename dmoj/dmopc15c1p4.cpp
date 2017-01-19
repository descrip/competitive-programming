#include <bits/stdc++.h>
using namespace std;

const int MAXN = 148734+5;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, x; cin >> n >> x;
	vector<int> v;
	for (int i = 0; i*x <= n; ++i)
		v.push_back(i*x);
	static bool p[MAXN];
	fill_n(p, MAXN, true);
	p[0] = p[1] = false;
	long long ans = 0;
	for (int i = 2; i <= n; ++i)
		if (p[i]){
			for (int j = 2; i*j <= n; ++j)
				p[i*j] = false;
			auto it = upper_bound(v.begin(), v.end(), n-i);
			--it;
			//cout << i << ' ' << *it << '\n';
			ans += (it-v.begin()+1) * 2;
			if (*it + i == n)
				--ans;
		}
	cout << ans << '\n';
return 0;}
