#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h1, m1, h2, m2, a, b;
    while (cin >> h1 >> m1 >> h2 >> m2) {
        if (h1 == 0 && h2 == 0 && m1 == 0 && m2 == 0)
            break;
        a = h1*60 + m1;
        b = h2*60 + m2;
        if (a <= b)
            cout << b-a << '\n';
        else
            cout << 24*60 - a + b << '\n';
    }
    return 0;
}

