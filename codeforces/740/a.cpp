#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long n, a[5], ans = 0xfffffffffff;
    cin >> n;
    for (int i = 1; i < 4; ++i)
        cin >> a[i];
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            for (int k = 0; k < 4; ++k)
                if ((n+i+2*j+3*k)%4 == 0)
                    ans = min(ans, a[1]*i+a[2]*j+a[3]*k);
    cout << ans << '\n';
	return 0;
}

