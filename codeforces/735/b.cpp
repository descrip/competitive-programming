#include <bits/stdc++.h>
using namespace std;

long long n, n1, n2, a[100001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> n1 >> n2;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a,a+n,greater<int>());
	if (n1 > n2) {
		swap(n1, n2);
	}
	long long tot = 0;
	for (int i = 0; i < n1; ++i)
		tot += a[i] * n2;
	for (int i = n1; i < n1+n2; ++i)
		tot += a[i] * n1;
	cout << fixed << setprecision(8) << (double) tot / ((long long) n1 * n2) << '\n';
	return 0;
}
