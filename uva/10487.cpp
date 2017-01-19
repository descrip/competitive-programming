#include <bits/stdc++.h>
using namespace std;

// i am very dumb

int N, A[1001], M, T = 1;
set<int> S;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> N) {
        if (N == 0) break;
        S.clear();
        for (int i = 0; i < N; ++i)
            cin >> A[i];
        for (int i = 0; i < N; ++i)
            for (int j = i+1; j < N; ++j)
                S.insert(A[i]+A[j]);
        cout << "Case " << T++ << ":\n";
        cin >> M;
        /*
        for (int i : S)
            cout << i << ' ';
        cout << '\n';
        */
        for (int i = 0; i < M; ++i) {
            int n; cin >> n;
            auto it = S.lower_bound(n);
            int x = *it, y;
            if (it == S.begin())
                y = x;
            else {
                --it;
                y = *it;
            }
            cout << "Closest sum to " << n << " is " << (abs(x-n) < abs(y-n) ? x : y) << ".\n";
        }
    }
    return 0;
}

