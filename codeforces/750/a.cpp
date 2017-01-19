#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n, k; cin >> n >> k;
    int t = 4*60 - k, tot = 0;
    while (tot <= n-1 && 5 * (tot+1) <= t) {
        t -= 5*(tot+1);
        tot++;
    }
    cout << tot << '\n';
	return 0;
}

