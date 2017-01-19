#include <bits/stdc++.h>
using namespace std;

int L;
string S;
vector<string> A;

bool zsort(const string &a, const string &b) {
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

void recur(char c) {
    if (S.size() == L) {
        A.push_back(S);
        return;
    }
    for (char d = c; d <= 'z'; ++d) {
        S += d;
        recur(d+1);
        S.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (L = 1; L <= 5; ++L)
        recur('a');
    while (cin >> S) {
        auto it = lower_bound(A.begin(), A.end(), S, zsort);
        cout << (*it != S ? 0 : (it - A.begin()) + 1) << '\n';
    }
    return 0;
}

