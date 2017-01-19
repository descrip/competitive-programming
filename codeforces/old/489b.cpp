#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> b (n);
	for (int i = 0; i < n; ++i)
		cin >> b[i];
	int m; cin >> m;
	vector<int> g (m);
	for (int i = 0; i < m; ++i)
		cin >> g[i];
	sort(b.begin(),b.end());
	sort(g.begin(),g.end());
	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (abs(b[i]-g[j]) <= 1){
				g[j] = -0xfffffff;
				++ans;
				break;
			}
	cout << ans << '\n';
return 0;}
