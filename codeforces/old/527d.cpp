#include <bits/stdc++.h>
using namespace std;

bool sortf(const pair<int,int> &a, const pair<int,int> &b){
	return a.first + a.second < b.first + b.second;
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<pair<int,int>> v;
	for (int i = 0; i < n; ++i){
		int a, b; cin >> a >> b;
		v.push_back({a,b});
	}
	sort(v.begin(),v.end(),sortf);
	int last = 0, ans = 1;
	for (int i = 1; i < n; ++i){
		if (v[last].first + v[last].second <= v[i].first - v[i].second){
			last = i;
			++ans;
		}
	}
	cout << ans << '\n';
return 0;}
