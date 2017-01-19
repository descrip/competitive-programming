#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for (int i = 1; i <= 1000; ++i)
        for (int j = 2; j*j < n*i+1; ++j)
            if ((n*i+1) % j == 0) {
                cout << i << '\n';
                return 0;
            }
    return 0;
}

