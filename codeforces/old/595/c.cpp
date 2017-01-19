#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	set<int> v;
	for (int i = 0; i < n; ++i){
		int a; cin >> a;
		v.insert(a);
	}
	set<pair<int,int>> s;
	for (auto it = v.begin(); it != v.end(); ++it){
		auto itl = --it, itr = ++it;
		int d = 0xfffffff;
		if (itr != v.end())
			d = min(d, *itr - *it);
		if (it != v.begin())
			d = min(d, *it - *itl);
		s.insert(make_pair(d, *it));
	}
	for (int coin = 0; coin < n; ++coin){
		if (coin % 2 == 0){

		}
		else if (coin % 2 == 1){
			auto it = s.begin(), it2 = ++it;
		}
	}
return 0;}

