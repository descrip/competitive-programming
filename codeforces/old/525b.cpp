#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	int m; cin >> m;
	vector<int> ds (s.size()+1,0);
	for (int i = 0; i < m; ++i){
		int a; cin >> a;
		ds[a-1] += 1;
		ds[s.size()-a+1] -= 1;
	}
	vector<char> ans;
	for (int i = 0; i < ds.size()-1; ++i){
		ds[i] += (i == 0 ? 0 : ds[i-1]);
		if (ds[i] % 2 == 0) ans.push_back(s[i]);
		else ans.push_back(s[s.size()-i-1]);
	}
	//for (int i : ds) cout << i << '\n';
	for (char c : ans) cout << c;
	cout << '\n';
return 0;}
