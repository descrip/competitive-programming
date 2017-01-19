#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	multiset<int> s;
	for (int i = 0; i < n*n; ++i){
		int a; cin >> a;
		s.insert(a);
	}
	vector<int> ans;
	for (int i = 0; i < n; ++i){
		int x = *s.rbegin();
		s.erase(s.find(x));
		cout << x << ' ';
		for (int j : ans){
			s.erase(s.find(__gcd(j,x)));
			s.erase(s.find(__gcd(j,x)));
		}
		ans.push_back(x);
	}
	cout << '\n';
return 0;}
