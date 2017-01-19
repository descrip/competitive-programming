#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s, r, t; cin >> s >> t;
	r = s; reverse(r.begin(), r.end());

	static bool has[256];
	for (char c : s)
		has[c] = true;
	for (char c : t)
		if (!has[c]){
			cout << "-1\n";
			return 0;
		}

	string x = "";
	int pos1 = 0, pos2 = 0;
	vector<pair<int,int>> ans;
	for (int i = 0; i < t.size(); ++i){
		int ppos1 = s.find(x+t[i]),
			ppos2 = r.find(x+t[i]);
		//cout << i << ' ' << x+t[i] << ' ' << pos1 << ' ' << pos2 << ' ' << ppos1 << ' ' << ppos2 << '\n';
		//cout << (ppos1 == string::npos) << ' ' << (ppos2 == string::npos) << '\n';
		if (ppos1 == string::npos && ppos2 == string::npos){
			if (pos1 != string::npos)
				ans.push_back({pos1+1, pos1+x.size()});
			else
				ans.push_back({s.size()-pos2, s.size()-pos2-x.size()+1});
			x = "";
			ppos1 = s.find(x + t[i]);
			ppos2 = r.find(x + t[i]);
			//cout << ppos1 << ' ' << ppos2 << '\n';
		}
		x += t[i];
		pos1 = ppos1; pos2 = ppos2;
	}
	if (pos1 != string::npos)
		ans.push_back({pos1+1, pos1+x.size()});
	else
		ans.push_back({s.size()-pos2, s.size()-pos2-x.size()+1});

	cout << ans.size() << '\n';
	for (pair<int,int> i : ans)
		cout << i.first << ' ' << i.second << '\n';
return 0;}

