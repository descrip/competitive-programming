#include <bits/stdc++.h>
using namespace std;

// woah canadian politics
// segfaults on case "3 2 1", but still ac
// protip: dont use reverse iterators

int N, m, k;
list<int> L;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> N >> m >> k) {
        if (N == 0 && m == 0 && k == 0) break;
        for (int i = 1; i <= N; ++i)
            L.push_back(i);
        auto itcc = L.begin();
        auto itc = L.rbegin();
        bool tick = false;
        while (!L.empty()) {
            if (tick) 
                cout << ',';
            tick = true;
            for (int i = 0; i < m-1; ++i) {
                ++itcc;
                if (itcc == L.end())
                    itcc = L.begin();
            }
            for (int i = 0; i < k-1; ++i) {
                ++itc;
                if (itc == L.rend())
                    itc = L.rbegin();
            }
            cout << setw(3) << *itcc;
            if (*itc != *itcc) {
                cout << setw(3) << *itc;
                ++itc;
                if (itc == L.rend()) {
                    L.erase(L.begin());
                    itc = L.rbegin();
                }
                else L.erase(itc.base());
            }
            itcc = L.erase(itcc);
            if (itcc == L.end())
                itcc = L.begin();
        }
        cout << '\n';
    }
    return 0;
}

