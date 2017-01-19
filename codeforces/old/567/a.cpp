#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> v (n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	sort(v.begin(),v.end());
	cout << v[1]-v[0] << ' ' << v[n-1]-v[0] << '\n';
	for (int i = 1; i < n-1; ++i){
		int a = max(v[i]-v[0],v[n-1]-v[i]);
		cout << min(v[i]-v[i-1],v[i+1]-v[i]) << ' ' << a << '\n';
	}
	cout << v[n-1]-v[n-2] << ' ' << v[n-1]-v[0] << '\n';
return 0;}
