#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int R, K; cin >> K >> R;
    for (int i = 1; i <= 10; ++i)
        if ((K*i) % 10 == 0 || (K*i-R) % 10 == 0) {
            cout << i << '\n';
            break;
        }
	return 0;
}

