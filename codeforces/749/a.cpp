#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N; cin >> N;
    cout << (int)ceil(N/2) << '\n';
    while (N > 1) {
        cout << (N == 3 ? 3 : 2) << ' ';
        N -= 2;
    }
    cout << '\n';
	return 0;
}

