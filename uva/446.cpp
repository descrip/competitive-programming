#include <bits/stdc++.h>
using namespace std;

int T;
string a, b, op;

int hex2dec(string s) {
    int ret = 0, tim = 1;
    for (int i = s.size()-1; i >= 0; --i) {
        ret += (s[i] - (s[i] >= 'A' ? ('A' - 10) : '0')) * tim;
        tim *= 16;
    }
    return ret;
}

int main() {
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> a >> op >> b;
        int x = hex2dec(a), y = hex2dec(b);
        bitset<13> c(x), d(y);
        cout << c << ' ' << op << ' ' << d << " = " << (op == "+" ? x+y : x-y) << '\n';
    }
    return 0;
}

