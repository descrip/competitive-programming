#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k; cin >> n >> k;
	vector<int> v (n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	sort(v.begin(),v.end());
	long long ans = 0;
	int last = 0;
	for (int i = 0; i <= n/k; ++i){
		int j;
		for (j = last+1; (j-last)*k < n; ++j){
			ans += v[j]-v[j-1];
			cout << v[j] << '\n';
		}
		//cout << 'j' << j << '\n';
		last = j;
		cout << 'a' << ans << '\n';
	}
	cout << ans << '\n';
return 0;}
