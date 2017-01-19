#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int k2, k3, k5, k6; cin >> k2 >> k3 >> k5 >> k6;
    int t = min(min(k5, k6), k2); 
    long long ans = 0;
    k2 -= t;
    ans += t * (256) + 32 * min(k2, k3);
    cout << ans << '\n';
	return 0;
}

