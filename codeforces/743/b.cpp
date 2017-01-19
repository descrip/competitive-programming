#include <bits/stdc++.h>
using namespace std;

long long n, k;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> n >> k;
    --k;
    while (n >= 1) {
        long long l = (1LL<<n) - 1;
        if (k == l/2) {
            cout << n << '\n';
            return 0;
        }
        else if (k > l/2)
            k = k - l/2 - 1;
        --n;
    }
	return 0;
}

