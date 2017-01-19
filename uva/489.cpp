#include <bits/stdc++.h>
using namespace std;

int R;
string S, T;
set<int> C, D;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    while (cin >> R) {
        if (R == -1)
            break;
        getline(cin, S);
        getline(cin, S);
        getline(cin, T);
        C.clear();
        D.clear();
        for (char c : S)
            C.insert(c);
        int cnt = 0;
        bool ok = false;
        cout << "Round " << R << '\n';
        for (char c : T) {
            if (C.count(c) == 1) {
                C.erase(c);
                if (C.empty()) {
                    cout << "You win.\n";
                    ok = true;
                    break;
                }
            }
            else if (D.count(c) == 0) {
                ++cnt;
                if (cnt == 7) {
                    cout << "You lose.\n";
                    ok = true;
                    break;
                }
            }
            D.insert(c);
        }
        if (!ok)
            cout << "You chickened out.\n";
    }
	return 0;
}

