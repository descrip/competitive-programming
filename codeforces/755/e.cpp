#include <bits/stdc++.h>
using namespace std;

int N, K;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    if (K >= N || K == 1)
        cout << "-1\n";
    else {
        cout << K << '\n';
        for (int i = 1; i <= K; ++i)
            cout << i << ' ' << i+1 << '\n';
    }
    return 0;
}

