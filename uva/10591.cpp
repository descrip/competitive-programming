#include <bits/stdc++.h>
using namespace std;

int T;
long long N;
set<long long> S;

long long sos(long long x) {
    long long ret = 0;
    while (x > 0) {
        ret += (x % 10) * (x % 10);
        x /= 10;
    }
    return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N;
        long long zN = N;
        S.clear();
        while (N != 1 && S.count(N) == 0) {
            S.insert(N);
            N = sos(N);
        }
        // english is hard
        printf("Case #%d: %lld is %s number.\n", t, zN, (N == 1 ? "a Happy" : "an Unhappy"));
    }
	return 0;
}

