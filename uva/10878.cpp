#include <bits/stdc++.h>
using namespace std;

string S, T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    getline(cin, S);
    while (getline(cin, S)) {
        if (S[0] == '_') break;
        int curr = 0;
        for (int i = 1; i < S.size()-1; ++i)
            if (S[i] == '.') continue;
            else curr = curr * 2 + (S[i] == 'o');
        T += (char)curr;
    }
    cout << T;
    return 0;
}

