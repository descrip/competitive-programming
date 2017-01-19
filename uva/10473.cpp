#include <bits/stdc++.h>
using namespace std;

string N;

int hex2dec(string s) {
    int ret = 0, pow = 1;
    for (int i = s.size()-1; i >= 2; --i) {
        ret += (s[i] - (s[i] >= 'A' ? 'A'-10 : '0')) * pow;
        pow *= 16;
    }
    return ret;
}

string dec2hex(int x) {
    if (x == 0)
        return "0x0";
    string ret;
    while (x >= 1) {
        ret = string(1, (x%16 >= 10 ? 'A' + x%16 - 10 : '0' + x%16)) + ret;
        x /= 16;
    }
    return "0x" + ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> N) {
        if (N[1] == 'x') cout << hex2dec(N) << '\n';
        else if (N[0] == '-') break;
        else cout << dec2hex(stoi(N)) << '\n';
    }
    return 0;
}

