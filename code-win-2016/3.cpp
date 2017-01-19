#include <bits/stdc++.h>
using namespace std;

int N, A[100005], M = 0x7fffffff;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        M = min(M, A[i]);
    }
    long long ans = 0;
    for (int i = 0; i < N; ++i)
        ans += A[i]-M;
    cout << ans << '\n';
	return 0;
}

