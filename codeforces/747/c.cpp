#include <bits/stdc++.h>
using namespace std;

int n, q, a[100];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < q; ++i) {
        int t, k, d; cin >> t >> k >> d;
        int sum = 0, cnt = 0;
        for (int i = 0; i < n; ++i)
            if (a[i] < t) {
                ++cnt;
                sum += i+1;
                if (cnt == k)
                    break;
            }
        if (cnt < k) {
            cout << "-1\n";
            continue;
        }
        for (int i = 0; i < n; ++i)
            if (a[i] < t) {
                a[i] = t+d-1;
                --cnt;
                if (cnt == 0)
                    break;
            }
        cout << sum << '\n';
    }
	return 0;
}

