#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	v.push_back(1);
	v.push_back(2);
	while (v.back() <= n)
		v.push_back(v.back() + v[v.size()-2]);
	auto it = lower_bound(v.begin(), v.end(), n);
	if (*it != n) --it;
	cout << it-v.begin() << '\n';
	return 0;
}
