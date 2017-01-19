#include <bits/stdc++.h>
using namespace std;

int N, Z = 0, T = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> N) {
        if (N == 0) break;
        Z = 0;
        for (int i = 0; i < N; ++i) {
            int a; cin >> a;
            Z += (a == 0 ? -1 : 1);
        }
        cout << "Case " << T++ << ": " << Z << '\n';
    }
    return 0;
}

