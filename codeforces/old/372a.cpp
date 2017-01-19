#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> all (n), v (n/2);
	multiset<int> s;
	for (int i = 0; i < n; ++i)
		cin >> all[i];
	sort(all.begin(), all.end());
	for (int i = 0; i < n/2; ++i){
		v[i] = all[n-i-1];
		s.insert(all[i]);
	}
	int ans = n;
	for (int i = 0; i < n/2; ++i){
		auto it = s.upper_bound(v[i]/2);
		if (it == s.begin())
			break;
		--it;
		//cout << v[i] << ' ' << s.size() << ' ' << (*it) << '\n';
		s.erase(it);
		--ans;
	}
	cout << ans << '\n';
return 0;}
