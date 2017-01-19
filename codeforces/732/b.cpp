#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int N, K; cin >> N >> K;
    int A[501];
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    int tot = 0;
    for (int i = 1; i < N; ++i) {
        int tmp = max(K-A[i-1]-A[i], 0);
        tot += tmp;
        A[i] += tmp;
    }
    cout << tot << '\n';
    for (int i = 0; i < N; ++i)
        cout << A[i] << ' ';
    cout << '\n';
	return 0;
}

