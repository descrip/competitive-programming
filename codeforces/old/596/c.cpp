#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<pair<pair<int,int>, pair<int,int>>> pts;
	for (int i = 0; i < n; ++i){
		int x, y; cin >> x >> y;
		pts.push_back({{x+y, y-x}, {x,y}});
	}
	sort(pts.begin(), pts.end());

	/*
	for (int i = 0; i < n; ++i)
		cout << pts[i].first.first << ' ' << pts[i].first.second << '\n';
		*/

	vector<int> w (n);
	for (int i = 0; i < n; ++i)
		cin >> w[i];
	vector<int> need;
	vector<pair<int,int>> ans, curr;

	for (int i = 0; i < n; ++i){
		int j = i;
		while (pts[j].first.first == pts[i].first.first)
			++j;
		--j;

		curr.clear();
		for (int k = i; k <= j; ++k){
			curr.push_back({pts[k].first.second, k});
			need.push_back(w[k]);
		}
		sort(curr.begin(), curr.end());
		sort(need.begin(), need.end());

		for (int k = 0; k < curr.size(); ++k)
			cout << curr[k].first << ' ';
		cout << '\n';
		for (int k = 0; k < curr.size(); ++k)
			cout << need[k] << ' ';
		cout << '\n';

		for (int k = 0; k < curr.size(); ++k)
			if (curr[k].first != need[k]){
				cout << "NO\n";
				return 0;
			}

		for (int k = 0; k < curr.size(); ++k){
			int t = curr[k].second;
			ans.push_back(pts[t].second);
		}

		i = j;
	}

	for (pair<int,int> i : ans)
		cout << i.first << ' ' << i.second << '\n';
return 0;}

