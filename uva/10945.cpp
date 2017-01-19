#include <bits/stdc++.h>
using namespace std;

string s, t;

bool mustIgnore(char c) {
    return (c == '.' || c == ',' || c == '!' || c == '?' || c == ' ');
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    while (true) {
        getline(cin, s);
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        s.erase(remove_if(s.begin(), s.end(), mustIgnore), s.end());
        if (s == "done")
            break;
        t = s;
        reverse(t.begin(), t.end());
        cout << (s == t ? "You won't be eaten!" : "Uh oh..") << '\n';
    }
	return 0;
}

