#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	static int a[100000], dp[100001];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	set<int> s;
	for (int i = n-1; i >= 0; --i){
		dp[i] = dp[i+1];
		if (s.count(a[i]) == 0){
			++dp[i];
			s.insert(a[i]);
		}
	}
	for (int i = 0; i < m; ++i){
		int l; cin >> l;
		cout << dp[l-1] << '\n';
	}
return 0;}
