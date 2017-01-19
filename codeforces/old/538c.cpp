#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	vector<int> h(m), d(m);
	for (int i = 0; i < m; ++i)
		cin >> d[i] >> h[i];
	if (d[0] != 1){
		d.insert(d.begin(),1);
		h.insert(h.begin(),h[0]+d[1]-1);
	}
	if (d[d.size()-1] != n){
		h.push_back(h[h.size()-1]+n-d[d.size()-1]);
		d.push_back(n);
	}
	int ans = h[h.size()-1];
	for (int i = 0; i < d.size()-1; ++i){
		if (abs(h[i]-h[i+1]) > d[i+1]-d[i]){
			//cout << i << ' ' << h[i] << ' ' << d[i] << ' ' << h[i+1] << ' ' << d[i+1] << '\n';
			cout << "IMPOSSIBLE\n";
			return 0;
		}
		ans = max(ans,h[i]);
		int lo = d[i], hi = d[i+1];
		while (lo + 1 < hi){
			int mid = lo+(hi-lo)/2;
			if (abs(h[i]+mid-d[i]-h[i+1]) <= d[i+1]-mid)
				lo = mid;
			else
				hi = mid;
		}
		ans = max(ans,lo-d[i]+h[i]);
	}
	cout << ans << '\n';
return 0;}
