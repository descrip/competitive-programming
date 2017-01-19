#include <bits/stdc++.h>
using namespace std;

long long dist(const pair<long long,long long> &a, const pair<long long,long long> &b){
	return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}

//CHECK INT

int main(){
	//ios_base::sync_with_stdio(0); cin.tie(0);
	long long n, x1, y1, x2, y2; cin >> n >> x1 >> y1 >> x2 >> y2;
	vector<pair<long long, long long>> p (n), vr1, vr2;
	pair<long long, long long> p1 = {x1, y1}, p2 = {x2, y2};
	for (int i = 0; i < n; ++i){
		cin >> p[i].first >> p[i].second;
		pair<long long, long long> tmp = {dist(p[i], p1), dist(p[i], p2)};
		vr1.push_back(tmp);
		vr2.push_back({tmp.second, tmp.first});
	}
	sort(vr2.begin(), vr2.end());
	set<pair<long long, long long>> sr1 (vr1.begin(), vr1.end());
	long long r1 = sr1.rbegin()->first, r2 = 0, ans = r1;
	for (int i = 0; i < vr2.size(); ++i){
		r2 = max(vr2[i].first, r2);
		auto it = sr1.find(make_pair(vr2[i].second, vr2[i].first));
		//cout << vr2[i].second << ' ' << vr2[i].first << ' ' << (it == sr1.end()) << '\n';
		sr1.erase(it);
		if (!sr1.empty())
			r1 = min(r1, sr1.rbegin()->first);
		ans = min(ans, r1 + r2);
	}
	cout << ans << '\n';
return 0;}

