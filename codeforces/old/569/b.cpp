#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> v (n);
	set<int> s;
	multiset<int> s2;
	for (int i = 1; i <= n; ++i)
		s.insert(i);
	for (int i = 0; i < n; ++i){
		cin >> v[i];
		s.erase(v[i]);
		s2.insert(v[i]);
	}
	for (int i = 0; i < n; ++i){
		if (v[i] > n || s2.count(v[i]) > 1){
			s2.erase(s2.find(v[i]));
			v[i] = *s.begin();
			s.erase(s.begin());
		}
		cout << v[i] << ' ';
	}
	cout << '\n';
return 0;}
