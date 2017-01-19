#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> v (n);
	vector<bool> b (n+1);
	set<int> s;
	for (int i = 1; i <= n; ++i)
		s.insert(i);
	for (int i = 0; i < n; ++i){
		cin >> v[i];
		if (v[i] > n || b[v[i]] == true)
			v[i] = -1;
		else b[v[i]] = true;
		s.erase(v[i]);
	}
	for (int i = 0; i < n; ++i){
		if (v[i] == -1){
			v[i] = *s.begin();
			s.erase(s.begin());
		}
		cout << v[i] << ' ';
	}
	cout << '\n';
return 0;}
