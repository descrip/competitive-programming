#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	set<pair<int,int>> s;
	for (int i = 0; i < n; ++i){
		int x, y; cin >> x >> y;
		s.insert({x,y});
	}
	vector<int> v (n);
	v[1] = s.first()->second;
	for (int i = 3; i < n; ++i)
return 0;}
