#include <bits/stdc++.h>
using namespace std;

int T, N, C[10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N;
        fill_n(C, 10, 0);
        while (N > 0) {
            int X = N;
            while (X > 0) {
                C[X%10]++;
                X /= 10;
            }
            N--;
        }
        for (int i = 0; i < 10; ++i)
            cout << C[i] << " \n"[i == 9];
    }
	return 0;
}

