#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> v (n);
	vector<char> t (n);
	set<int> ins, alr;
	for (int i = 0; i < n; ++i){
		cin >> t[i] >> v[i];
		if (t[i] == '-' && ins.count(v[i]) == 0)
			alr.insert(v[i]);
		else if (t[i] == '-')
			ins.erase(v[i]);
		else if (t[i] == '+')
			ins.insert(v[i]);
	}
	int ans = alr.size();
	for (int i = 0; i < n; ++i){
		if (t[i] == '-')
			alr.erase(v[i]);
		else
			alr.insert(v[i]);
		ans = max(ans,(int)alr.size());
	}
	cout << ans << '\n';
return 0;}
