/*
ID: jezhao11
LANG: C++11
TASK: prefix
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("prefix.in", "r", stdin);
	freopen("prefix.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<string> prim;
	string tmp, s;
	while (cin >> tmp){
		prim.push_back(tmp);
		if (tmp == ".")
			break;
	}
	bool dp[200001];
	fill_n(dp, 200001, false);
	while (cin >> tmp)
		s += tmp;
	dp[0] = true;
	int len = 0;
	for (int i = 1; i <= s.size(); ++i)
		for (int j = 0; j < prim.size(); ++j)
			if (dp[i]){
				len = i;
				break;
			}
			else if (prim[j].size() <= i && dp[i-prim[j].size()])
				for (int k = 0; k < prim[j].size(); ++k)
					if (prim[j][k] != s[i-prim[j].size()+k])
						break;
					else if (k == prim[j].size()-1)
						dp[i] = true;
	cout << len << '\n';
return 0;}

