#include <bits/stdc++.h>
using namespace std;

int zmod(int a, int b) {
    return (a%b+b)%b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    string S; cin >> S;
    int A, B;
    for (int i = 0; i < S.size(); ++i)
        for (int j = i+1; j < S.size(); ++j)
            if (S[i] == S[j]) {
                A = i;
                B = j;
                break;
            }
    if (A == B-1) {
        cout << "Impossible\n"; return 0;
    }
    int C = (B-A-1)/2;
    //cout << A << ' ' << B << '\n';
    //cout << C << '\n';
    char ans[2][13];
    fill_n(ans[0], 2*13, '0');
    ans[0][12-C] = S[A];

    vector<pair<int, int>> P;
    for (int x = 0; x < 13; ++x)
        P.push_back({0, x});
    for (int x = 12; x >= 0; --x)
        P.push_back({1, x});

    int PA = find(P.begin(), P.end(), make_pair(0, 12-C)) - P.begin();
    //cout << PA << ' ' << PB << '\n';
    for (int i = zmod(PA - A, 26), j = 0; i != PA; i=(i+1)%26, ++j)
        ans[P[i].first][P[i].second] = S[j];
    for (int i = zmod(PA+1, 26), j = A+1; j < S.size(); i=(i+1)%26, ++j) {
        if (j == B) {
            i = zmod(i-1, 26);
            continue;
        }
        ans[P[i].first][P[i].second] = S[j];
    }

    for (int y = 0; y < 2; ++y) {
        for (int x = 0; x < 13; ++x)
            cout << ans[y][x];
        cout << '\n';
    }
	return 0;
}
