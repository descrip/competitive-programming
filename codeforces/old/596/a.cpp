#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	if (n == 1){
		cout << -1 << '\n';
		return 0;
	}
	vector<pair<int,int>> v (n);
	for (int i = 0; i < n; ++i)
		cin >> v[i].first >> v[i].second;
	if (n == 2 && (v[0].first == v[1].first || v[0].second == v[1].second)){
		cout << -1 << '\n';
		return 0;
	}
	else if (n == 2){
		cout << abs(v[1].first - v[0].first) * abs(v[1].second - v[0].second) << '\n';
		return 0;
	}
	int l, w;
	for (int i = 0; i < n; ++i)
		for (int j = i+1; j < n; ++j)
			if (v[i].first == v[j].first)
				w = abs(v[i].second - v[j].second);
			else if (v[i].second == v[j].second)
				l = abs(v[i].first - v[j].first);
	cout << l * w << '\n';
return 0;}

