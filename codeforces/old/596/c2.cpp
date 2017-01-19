#include <bits/stdc++.h>
using namespace std;

inline int manhat(const pair<int,int> &a, const pair<int,int> &b){
	return abs(a.first - b.first) + abs(a.second - b.second);
}

bool vsort(const pair<int,int> &a, const pair<int,int> &b){
	return manhat(a, {0,0}) < manhat(b, {0,0});
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<pair<int,int>> pts (n);
	for (int i = 0; i < n; ++i)
		cin >> pts[i].first >> pts[i].second;
	sort(pts.begin(), pts.end(), vsort);

	set<pair<int,int>> ser;
	for (int i = 0; i < n; ++i)
		ser.insert(pts[i]);

	vector<int> w (n);
	for (int i = 0; i < n; ++i)
		cin >> w[i];

	set<pair<int, pair<int,int>>> s;
	s.insert({0, {0,0}});
	ser.erase({0, 0});

	int curr = 0;
	vector<pair<int,int>> ans;

	while (!s.empty()){
		//cout << curr << ' ' << s.size() << '\n';
		auto it = s.lower_bound(make_pair(w[curr], make_pair(-1, -1)));
		if (it == s.end() || it->first != w[curr]){
			cout << "NO\n";
			return 0;
		}

		pair<int,int> p = it->second;
		//cout << p.first << ' ' << p.second << '\n';
		if (ser.count(make_pair(p.first+1, p.second)) != 0){
			auto it2 = s.lower_bound(make_pair(p.second - (p.first+1), make_pair(p.first+1, p.second)));
			//cout << it2->second.first << ' ' << it2->second.second << '\n';
			if (it2 == s.end() || it2->second != make_pair(p.first+1, p.second)){
				//cout << "ADD " << p.first+1 << ' ' << p.second << '\n';
				s.insert(make_pair(p.second - (p.first+1), make_pair(p.first+1, p.second)));
				ser.erase(make_pair(p.first+1, p.second));
			}
		}
		if (ser.count(make_pair(p.first, p.second+1)) != 0){
			auto it2 = s.lower_bound(make_pair(it->first+1, make_pair(p.first, p.second+1)));
			if (it2 == s.end() || it2->second != make_pair(p.first, p.second+1)){
				//cout << "ADD " << p.first << ' ' << p.second+1 << '\n';
				s.insert(make_pair(it->first+1, make_pair(p.first, p.second+1)));
				ser.erase(make_pair(p.first, p.second+1));
			}
		}
		ans.push_back(it->second);
		s.erase(it);
		++curr;
	}
	cout << "YES\n";
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i].first << ' ' << ans[i].second << '\n';
return 0;}

