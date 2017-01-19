#include <bits/stdc++.h>
using namespace std;

int T, N, M, A[100005];

bool poss(int d) {
    int n = N;
    for (int i = 0; i < M; ++i) {
        for (int j = i+1; j < M; ++j)
            if (A[j]-A[i] > d) {
                //cout << d << ' ' << i << ' ' << j << '\n';
                --n;
                if (n == 0) 
                    return false;
                i = j-1;
                break;
            }
            else if (j == M-1)
                return true;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N >> M;
        for (int i = 0; i < M; ++i)
            cin >> A[i];
        sort(A, A+M);
        int lo = 0, hi = 2e9, mid;
        while (lo < hi) {
            mid = lo + (hi-lo)/2;
            if (poss(mid)) hi = mid;
            else lo = mid+1;
        }
        cout << fixed << setprecision(1) << lo/2.0 << '\n';
    }
    return 0;
}

