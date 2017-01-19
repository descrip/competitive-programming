#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	static int a[100000];
	static set<int> b[100000];
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		int c = a[i];
		while (c <= 2000000){
			b[i].insert(c);
			c *= 2;
		}
		c = a[i];
		while (c >= 1){
			b[i].insert(c);
			c /= 2;
		}
	}
	int ans = 0xfffffff;
	for (int i : b[0]){
		int tmp = 0;
		for (int j = 0; j < n; ++j){
			if (b[j].count(i) == 0)
				break;
			else{
				if (i >= a[j])
					tmp += log2(i/a[j]);
				else
					tmp += log2(a[j]/i);
				if (j == n-1)
					ans = min(ans,tmp);
			}
		}
	}
	cout << ans << '\n';
return 0;}
