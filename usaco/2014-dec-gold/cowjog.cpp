#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("cowjog.in", "r", stdin);
	freopen("cowjog.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, t; cin >> n >> t;
	vector<long long> v;
	for (int i = 0; i < n; ++i){
		long long a, b; cin >> a >> b;
		b = -(a+b*t);
		if (v.empty() || b >= v.back())
			v.push_back(b);
		else
			*upper_bound(v.begin(), v.end(), b) = b;
	}
	cout << v.size() << '\n';
return 0;}
