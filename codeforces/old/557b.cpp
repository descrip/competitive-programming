#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n, w; cin >> n >> w;
	vector<int> a (2*n);
	for (int i = 0; i < 2*n; ++i)
		cin >> a[i];
	sort(a.begin(),a.end());
	int x = a[0], y = a[n];
	double ans = min((double)x,(double)y/2) * 3 * n;
	cout << fixed << setprecision(9) << min(ans,(double)w) << '\n';
return 0;}
