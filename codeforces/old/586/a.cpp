#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	while (true){
		if (v.empty()){
			cout << 0 << '\n';
			return 0;
		}
		else if (v[0] == 0)
			v.erase(v.begin());
		else if (v[v.size()-1] == 0)
			v.pop_back();
		else
			break;
	}
	int ans = 0;
	for (int i = 0; i < v.size(); ++i)
		if (v[i] == 1 || (v[i] == 0 && !(v[i+1] == 0 || v[i-1] == 0)))
			++ans;
	cout << ans << '\n';
return 0;}
