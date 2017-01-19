#include <bits/stdc++.h>
using namespace std;

int N, A[1000005];

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    long long meh = A[0], msf = A[0];
    for (int i = 1; i < N; ++i) {
        meh = max((long long)A[i], meh+A[i]);
        msf = max(msf, meh);
    }
    cout << msf << '\n';
	return 0;
}

