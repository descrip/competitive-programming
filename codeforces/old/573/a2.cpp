#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> v (n);
	for (int i = 0; i < n; ++i){
		cin >> v[i];
		while (v[i]%2 == 0)
			v[i] /= 2;
		while (v[i]%3 == 0)
			v[i] /= 3;
	}
	for (int i = 1; i < n; ++i)
		if (v[i] != v[0]){
			cout << "No\n";
			return 0;
		}
	cout << "Yes\n";
return 0;}
