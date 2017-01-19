#include <bits/stdc++.h>
using namespace std;

int G;
string S;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    while (cin >> G) {
        if (G == 0) break;
        cin >> S;
        int L = S.size() / G;
        for (int i = 0; i < S.size(); i += L)
            reverse(S.begin()+i, S.begin()+i+L);
        cout << S << '\n';
    }
	return 0;
}

