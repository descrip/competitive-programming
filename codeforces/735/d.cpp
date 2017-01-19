#include <bits/stdc++.h>
using namespace std;

const long long MAXN = 2000000005;
long long n;

bool isP(long long x) {
	for (long long i = 2; i*i <= x; ++i)
		if (x % i == 0)
			return false;
	return true;
}

int main() {
	cin >> n;
	if (n % 2 == 0) {
		if (n == 2) cout << "1\n";
		else cout << "2\n";
	}
	else if (n % 2 == 1) {
		if (isP(n)) cout << "1\n";
		else if (isP(n-2)) cout << "2\n";
		else cout << "3\n";
	}
	return 0;
}
