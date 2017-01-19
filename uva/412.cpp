#include <bits/stdc++.h>
using namespace std;

int N, A[51];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    while (cin >> N) {
        if (N == 0) break;
        for (int i = 0; i < N; ++i)
            cin >> A[i];
        int cnt = 0;
        for (int i = 0; i < N; ++i)
            for (int j = i+1; j < N; ++j)
                cnt += (__gcd(A[i], A[j]) == 1);
        double prob = (double) cnt / (N * (N-1) / 2);
        if (cnt == 0)
            cout << "No estimate for this data set.\n";
        else
            cout << fixed << setprecision(6) << sqrt(6 / prob) << '\n';
    }
	return 0;
}

