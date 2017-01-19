#include <vector>
#include <iostream>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	vector<long long> c (m), f(n+1);
	for (int i = 0; i < m; ++i)
		cin >> c[i];
	f[0] = 1;
	for (int i = m-1; i >= 0; --i)
		for (int j = 1; j <= n; ++j)
			if (j >= c[i])
				f[j] += f[j-c[i]];
	cout << f[n] << '\n';
return 0;}
