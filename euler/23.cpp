#include <bits/stdc++.h>
using namespace std;

int sumDiv(int n){
	int ret = 0;
	for (int i = 1; i*i <= n; ++i)
		if (n % i == 0){
			ret += i;
			if (n / i != i)
				ret += n / i;
		}
	return ret - n;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<int> v;
	set<int> s;
	for (int i = 1; i < 28123; ++i)
		s.insert(i);
	for (int i = 1; i < 28123; ++i)
		if (sumDiv(i) > i){
			v.push_back(i);
			for (int j : v)
				s.erase(i+j);
		}
	int ans = 0;
	for (int i : s)
		ans += i;
	cout << ans << '\n';
return 0;}

