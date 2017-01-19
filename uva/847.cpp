#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> N) {
        int i = 0;
        for (; N > 1; ++i)
            N = ceil((double)N / (i % 2 == 0 ? 9 : 2));
        cout << (i % 2 == 1 ? "Stan" : "Ollie") << " wins.\n";
    }
    return 0;
}

