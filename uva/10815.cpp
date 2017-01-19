#include <bits/stdc++.h>
using namespace std;

string S, T;
set<string> ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    while (getline(cin, S)) {
        S += '~';
        for (char c : S) {
            char cc = tolower(c);
            if (!('a' <= cc && cc <= 'z')) {
                if (!T.empty()) {
                    ans.insert(T);
                    T = "";
                }
                continue;
            }
            else T += cc;
        }
    }
    for (string w : ans)
        cout << w << '\n';
	return 0;
}

