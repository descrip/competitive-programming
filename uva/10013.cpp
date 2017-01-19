#include <bits/stdc++.h>
using namespace std;

int N, M, A[1000001], B[1000001][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> N;
    for (int n = 0; n < N; ++n) {
        cin >> M;
        int carry = 0;
        for (int i = M-1; i >= 0; --i) {
            int a, b; cin >> a >> b;
            B[i][0] = a; B[i][1] = b;
        }
        for (int i = 0; i < M; ++i) {
            int tmp = B[i][0] + B[i][1] + carry;
            carry = tmp / 10;
            A[i] = tmp % 10;
        }
        for (int i = M-1; i >= 0; --i)
            cout << A[i];
        cout << '\n';
        if (n != N-1)
            cout << '\n';
    }
	return 0;
}

