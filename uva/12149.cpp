#include <bits/stdc++.h>
using namespace std;

long long N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> N) {
        if (N == 0) break;
        // sum of squares
        cout << N * (N+1) * (2*N+1) / 6 << '\n';
    }
    return 0;
}

