#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<string> v (n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	int ans = 0;
	for (char i = 'a'; i <= 'z'; ++i)
		for (char j = 'a'; j <= 'z'; ++j)
			if (i != j){
				int cnt = 0;
				for (string k : v)
					for (int l = 0; l < k.size(); ++l)
						if (k[l] != i && k[l] != j)
							break;
						else if (l == k.size()-1)
							cnt += k.size();
				ans = max(ans, cnt);
			}
	cout << ans << '\n';
return 0;}
