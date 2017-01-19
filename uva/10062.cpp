#include <bits/stdc++.h>
using namespace std;

string S;
multiset<int> C;
vector<pair<int, int>> V;
bool first = true;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    while (getline(cin, S)) {
        // WHY
        if (!first)
            cout << '\n';
        first = false;
        C.clear();
        V.clear();
        for (char c : S)
            C.insert((int)c);
        for (int i = 32; i < 128; ++i) {
            int x = C.count(i);
            if (x != 0)
                V.push_back({x, -i});
        }
        sort(V.begin(), V.end());
        for (auto p : V)
            cout << -p.second << ' ' << p.first << '\n';
    }
	return 0;
}

