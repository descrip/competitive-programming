#include <bits/stdc++.h>
using namespace std;

int N, A[10005];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    while (cin >> N) {
        if (N == 0)
            break;
        for (int i = 0; i < N; ++i)
            cin >> A[i];
        int curr = 0, ans = 0;
        for (int i = 0; i < N; ++i) {
            curr = max(0, curr+A[i]);
            ans = max(ans, curr);
        }
        if (ans == 0)
            cout << "Losing streak.\n";
        else cout << "The maximum winning streak is " << ans << ".\n";
    }
	return 0;
}

