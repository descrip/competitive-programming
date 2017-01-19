#include <bits/stdc++.h>
using namespace std;

int val[] = {2, 5, 4, 4, 1, 6, 5, 5, 1, 7, 6, 3, 5, 2, 3, 5, 7, 2, 1, 2, 4, 6, 6, 7, 5, 7};

bool canCreate(const string &have, const string &target1, const string &target2){
	static int cnt[26];
	fill_n(cnt, 26, 0);
	for (char c : have)
		++cnt[c-'a'];
	for (char c : target1)
		--cnt[c-'a'];
	for (char c : target2)
		--cnt[c-'a'];
	for (int i = 0; i < 26; ++i)
		if (cnt[i] < 0)
			return false;
	return true;
}

bool canCreate(const string &have, const string &target){
	return canCreate(have, target, "");
}

int getVal(const string &s){
	int ret = 0;
	for (char c : s)
		ret += val[c-'a'];
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	stringstream ss;
	string tmp;
	while (cin >> tmp){
		if (tmp == ".")
			break;
		ss << tmp << '\n';
	}
	string have; cin >> have;
	vector<string> dict;
	while (ss >> tmp)
		if (canCreate(have, tmp))
			dict.push_back(tmp);
	vector<pair<string, string>> ans;
	int bestVal = 0;
	for (int i = 0; i < dict.size(); ++i){
		int currVal = getVal(dict[i]);
		if (currVal > bestVal){
			ans = {{dict[i], ""}};
			bestVal = currVal;
		}
		else if (currVal == bestVal)
			ans.push_back({dict[i], ""});
		for (int j = i; j < dict.size(); ++j){
			if (!canCreate(have, dict[i], dict[j]))
				continue;
			int jVal = getVal(dict[j]);
			currVal += jVal;
			if (currVal > bestVal){
				ans = {{dict[i], dict[j]}};
				bestVal = currVal;
			}
			else if (currVal == bestVal)
				ans.push_back({dict[i], dict[j]});
			currVal -= jVal;
		}
	}
	cout << bestVal << '\n';
	for (pair<string, string> p : ans)
		cout << p.first << ' ' << p.second << '\n';
return 0;}

