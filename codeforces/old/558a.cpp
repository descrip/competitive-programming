#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<pair<int,int>> left, right;
	for (int i = 0; i < n; ++i){
		int a, b; cin >> a >> b;
		if (a < 0)
			left.push_back({a,b});
		else
			right.push_back({a,b});
	}
	sort(left.begin(),left.end(),greater<pair<int,int>>());
	sort(right.begin(),right.end());
	int ans = 0;
	for (int i = 0; i < min(left.size(),right.size())+1; ++i){
		if (i < right.size())
			ans += right[i].second;
		if (i < left.size())
			ans += left[i].second;
	}
	cout << ans << '\n';
return 0;}
