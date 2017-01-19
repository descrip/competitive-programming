#include <bits/stdc++.h>
using namespace std;

int T, N, M;
string A[101];
map<string, int> R;

int unsortedness(string s) {
    int ret = 0;
    for (int i = 0; i < s.size(); ++i)
        for (int j = i+1; j < s.size(); ++j)
            ret += (s[j] < s[i]);
    return ret;
}

bool ussort(const string &a, const string &b) {
    return R[a] < R[b];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        if (t != 1)
            cout << '\n';
        cin >> N >> M;
        for (int i = 0; i < M; ++i) {
            cin >> A[i];
            R[A[i]] = unsortedness(A[i]);
        }
        stable_sort(A, A+M, ussort);
        for (int i = 0; i < M; ++i)
            cout << A[i] << '\n';
    }
    return 0;
}

