#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> v (n), w (n, 0xfffffff);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	for (int i = 0; i < n; ++i){
		for (int j = 0; j <= i; ++j)
			w[i] = min(w[i], max(0,v[j]-j));
		for (int j = n-1; j > i; --j)
			w[i] = min(w[i], max(0,v[j]-(n-1-j)));
		cout << w[i] << ' ';
	}
	cout << '\n';
	cout << *max_element(w.begin(),w.end()) << '\n';
return 0;}
