/*
ID: jezhao11
LANG: C++11
TASK: lamps
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("lamps.in", "r", stdin);
	freopen("lamps.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, c; cin >> n >> c;
	set<int> on, off;
	int a = 0;
	while (true){
		cin >> a;
		if (a == -1)
			break;
		on.insert(a);
	}
	while (true){
		cin >> a;
		if (a == -1)
			break;
		off.insert(a);
	}

	vector<vector<bool>> ans;
	for (int i = 0; i < (1<<4); ++i){
		if (__builtin_popcount(i) > c || (c - __builtin_popcount(i)) % 2 == 1)
			continue;
		vector<bool> curr (n, true);
		if ((i & 1) != 0){
			for (int j = 0; j < n; ++j)
				curr[j] = !curr[j];
		}
		if ((i & 2) != 0){
			for (int j = 1; j <= n; j+=2)
				curr[j-1] = !curr[j-1];
		}
		if ((i & 4) != 0){
			for (int j = 2; j <= n; j+=2)
				curr[j-1] = !curr[j-1];
		}
		if ((i & 8) != 0){
			for (int j = 1; j <= n; j+=3)
				curr[j-1] = !curr[j-1];
		}
		for (int j = 0; j < n; ++j){
			if ((on.count(j+1) && !curr[j]) || (off.count(j+1) && curr[j]))
				break;
			else if (j == n-1)
				ans.push_back(curr);
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); ++i){
		for (bool j : ans[i])
			cout << j;
		cout << '\n';
	}
	if (ans.size() == 0)
		cout << "IMPOSSIBLE\n";
return 0;}
