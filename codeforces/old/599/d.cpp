#include <bits/stdc++.h>
using namespace std;

/*
inline long double func(long long x, long long n){
	return (long double)(x - n*(n-1)*(2*n-1)/6 + n*n*(n-1)/2) / (n*n - n*(n-1)/2);
}
*/

inline long double func(long long x, long long n){
	return (long double)(n*n*n - n + 6 * x) / (3 * n * n + 3 * n);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<pair<long long, long long>> ans;
	long long x; cin >> x;
	//cout << func(200200, 71) << '\n';
	for (long long n = 1; n <= 2*pow(x,1.0/3); ++n){
		long double m = func(x, n);
		if (m >= n && floor(m) == m){
			//cout << n << '\n';
			ans.push_back(make_pair(n, m));
		}
	}
	cout << ans.size()*2 - (ans[ans.size()-1].first == ans[ans.size()-1].second) << '\n';
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i].first << ' ' << ans[i].second << '\n';
	for (int i = ans.size()-1; i >= 0; --i)
		if (ans[i].first != ans[i].second)
			cout << ans[i].second << ' ' << ans[i].first << '\n';
return 0;}

