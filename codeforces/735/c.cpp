#include <bits/stdc++.h>
using namespace std;

long long n;

bool ispow2(long long x) {
	if (x == 1)
		return true;
	else if (x % 2 == 1)
		return false;
	else return ispow2(x / 2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int x = floor(log2((long double) n));
	if (ispow2(n)) cout << x << '\n';
	else cout << x+1 << '\n';
	return 0;
}
