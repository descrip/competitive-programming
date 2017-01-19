#include <bits/stdc++.h>
using namespace std;

int main(){
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k, a; cin >> n >> k >> a;
	int m; cin >> m;
	set<pair<int,int>> s;
	s.insert({0,0});
	s.insert({n+1,n/a});
	int tot = n/a;
	for (int i = 0; i < m; ++i){
		int z; cin >> z;
		auto itup = s.upper_bound({z,-1});
		auto itlo = itup; --itlo;

		tot -= itup->second;
		int up = itup->first;
		int lo = itlo->first;
		s.erase(itup);

		s.insert({up,(up-z)/(a+1)});
		tot += (up-z)/(a+1);

		s.insert({z,(z-lo)/(a+1)});
		tot += (z-lo)/(a+1);

		if (tot < k){
			cout << i+1 << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';
return 0;}
