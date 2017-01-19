#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long N; bool tick = false;
    while (cin >> N) {
        if (tick)
            cout << '\n';
        tick = true;
        bool leap = false, ord = true;
        if (N%4 == 0 && (N%400 == 0 || N%100 != 0)) {
            leap = true;
            ord = false;
            cout << "This is leap year.\n";
        }
        if (N%15 == 0) {
            ord = false;
            cout << "This is huluculu festival year.\n";
        }
        if (leap && N%55 == 0) {
            ord = false;
            cout << "This is bulukulu festival year.\n";
        }
        if (ord) {
            cout << "This is an ordinary year.\n";
        }
    }
    return 0;
}

