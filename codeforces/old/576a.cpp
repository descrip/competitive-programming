#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	bool prime[1001];
	fill_n(prime, 1001, true);
	prime[0] = prime[1] = false;
	set<int> ans;
	for (int i = 2; i <= n; ++i)
		if (prime[i]){
			for (int j = 2; i*j <= n; ++j)
				prime[i*j] = false;
			ans.insert(i);
			int tmp = i;
			while (tmp <= n){
				ans.insert(tmp);
				tmp *= i;
			}
		}
	cout << ans.size() << '\n';
	for (int i : ans)
		cout << i << ' ';
	cout << '\n';
return 0;}
