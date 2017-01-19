#include <bits/stdc++.h>
using namespace std;

int T, cnt, sum;
string S;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> S;
        cnt = sum = 0;
        for (char c : S) {
            if (c == 'O') ++cnt;
            else cnt = 0;
            sum += cnt;
        }
        cout << sum << '\n';
    }
    return 0;
}

