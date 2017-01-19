/*
ID: jezhao11
LANG: C++11
TASK: hamming
*/

#include <bits/stdc++.h>
using namespace std;

inline int hammingDist(int a, int b, int r){
	int ret = 0;
	for (int i = 0; i < r; ++i){
		if ((a & (1<<i)) != (b & (1<<i)))
			++ret;
	}
	return ret;
}

int main(){
	freopen("hamming.in", "r", stdin);
	freopen("hamming.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, b, d; cin >> n >> b >> d;
	vector<int> ans = {0};
	for (int i = 1; i <= (1<<b); ++i){
		if (ans.size() == n)
			break;
		bool ok = true;
		for (int j = 0; j < ans.size(); ++j)
			if (hammingDist(ans[j], i, b) < d)
				ok = false;
		if (ok)
			ans.push_back(i);
	}
	for (int i = 0; i < n; ++i)
		cout << ans[i] << " \n"[(i+1) % 10 == 0 || i == n-1];
return 0;}
