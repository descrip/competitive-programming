#include <bits/stdc++.h>
using namespace std;

// another waterloo problem woah

string S, T;
map<string, string> M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (getline(cin, S)) {
        if (S == "") break;
        stringstream ss(S);
        ss >> S >> T;
        M[T] = S;
    }
    while (cin >> S)
        cout << (M.count(S) == 0 ? "eh" : M[S]) << '\n';
    return 0;
}

