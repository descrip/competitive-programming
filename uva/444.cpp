#include <bits/stdc++.h>
using namespace std;

string encode(string s) {
    string ret = "";
    for (char c : s)
        ret += to_string((int)c);
    reverse(ret.begin(), ret.end());
    return ret;
}

string decode(string s) {
    reverse(s.begin(), s.end());
    string ret = "";
    int curr = 0;
    for (char c : s) {
        curr = curr * 10 + (c - '0');
        if (curr >= 32) {
            ret += (char) curr;
            curr = 0;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    while (getline(cin, s)) {
        if ('0' <= s[0] && s[0] <= '9')
            cout << decode(s) << '\n';
        else
            cout << encode(s) << '\n';
    }
    return 0;
}

