#include <bits/stdc++.h>
using namespace std;

vector<long long> M = {0}, F = {1};
int N;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    while (true) {
        F.push_back(M.back() + 1);
        M.push_back(F[F.size()-2] + M.back());
        if (M.back() >= (1LL << 32) || F.back() >= (1LL << 32))
            break;
    }
    while (cin >> N) {
        if (N == -1)
            break;
        cout << M[N] << ' ' << M[N]+F[N] << '\n';
    }
	return 0;
}

