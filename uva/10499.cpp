#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    long long n;
    while (cin >> n) {
        if (n < 0) break;
        else if (n == 1) cout << "0%\n";
        else cout << n*25 << "%\n";
    }
	return 0;
}

