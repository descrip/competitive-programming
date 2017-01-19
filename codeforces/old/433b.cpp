#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> u(n+1), v(n+1);
	for (int i = 1; i <= n; ++i)
		cin >> v[i];
	u = v;
	sort(u.begin(),u.end());
	vector<long long> udp(n+1), vdp(n+1);
	for (int i = 1; i <= n; ++i){
		udp[i] = udp[i-1] + u[i];
		vdp[i] = vdp[i-1] + v[i];
	}
	int m; cin >> m;
	for (int i = 0; i < m; ++i){
		int t, l, r; cin >> t >> l >> r;
		if (t == 1)
			cout << vdp[r] - vdp[l-1] << '\n';
		else
			cout << udp[r] - udp[l-1] << '\n';
	}
return 0;}
