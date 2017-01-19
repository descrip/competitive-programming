#include <bits/stdc++.h>
using namespace std;

const int LIM = (1e6)+1;
bool S[LIM];    // shady

int d(int n) {
    int x = n;
    while (x > 0) {
        n += x%10;
        x /= 10;
    }
    return n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fill_n(S, LIM, true);
    S[0] = false;
    for (int i = 1; i <= 1e6; ++i) 
        if (S[i]) {
            for (int j = d(i); j <= 1e6; j = d(j))
                if (!S[j]) break;
                else S[j] = false;
            cout << i << '\n';
        }
    return 0;
}

