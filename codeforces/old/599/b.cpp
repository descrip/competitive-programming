#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	vector<int> f (n+1), b (m+1);
	for (int i = 1; i <= n; ++i)
		cin >> f[i];
	for (int i = 1; i <= m; ++i)
		cin >> b[i];
	static int cnt[100010];
	set<pair<int,int>> s;
	set<int> bs;
	for (int i = 1; i <= n; ++i)
		s.insert({f[i], i});
	for (int i = 1; i <= m; ++i)
		bs.insert(b[i]);
	for (int i = 1; i <= m; ++i)
		if (s.lower_bound(make_pair(b[i], -1)) == s.end() || s.lower_bound(make_pair(b[i], -1))->first != b[i]){
			cout << "Impossible\n";
			return 0;
		}
	for (int i = 1; i <= n; ++i)
		if (cnt[f[i]] != 0 && bs.count(f[i]) != 0){
			cout << "Ambiguity\n";
			return 0;
		}
		else
			++cnt[f[i]];
	cout << "Possible\n";
	for (int i = 1; i <= m; ++i)
		cout << s.lower_bound(make_pair(b[i], -1))->second << ' ';
	cout << '\n';
return 0;}

