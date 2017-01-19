#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k; cin >> n >> k;
	vector<int> v (n);
	vector<pair<int,int>> r;
	for (int i = 0; i < n; ++i){
		cin >> v[i];
		if (v[i] == 100)
			r.push_back({0, i});
		else
			r.push_back({(v[i]/10+1)*10 - v[i], i});
	}
	sort(r.begin(), r.end());
	for (int i = 0; i < n; ++i){
		if (r[i].first > k)
			break;
		k -= r[i].first;
		v[r[i].second] += r[i].first;
	}
	for (int i = 0; i < n; ++i){
		if (k > 0){
			if (v[i] + k > 100){
				k -= (100 - v[i]);
				v[i] = 100;
			}
			else{
				v[i] += k;
				break;
			}
		}
		else break;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
		ans += v[i]/10;
	cout << ans << '\n';
return 0;}
