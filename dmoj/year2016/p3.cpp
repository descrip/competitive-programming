#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	vector<int> v (N, 0);
	for (int i = 0; i < N; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());
	set<int> s (v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < i; ++j){
			if (v[i] == v[j]){
				if (v[i+1] == v[j])
					ans = max(ans, 3*v[i]);
			}
			else if (s.count(v[i]*2 - v[j]))
				ans = max(ans, 3*v[i]);
		}
	cout << ans << '\n';
return 0;}

