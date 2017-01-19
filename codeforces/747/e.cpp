#include <bits/stdc++.h>
using namespace std;

int n, m = 0;
string s, t;
vector<string> v, d[1000005];

int recur(int pos, int dep) {
    m = max(dep, m);
    d[dep].push_back(v[pos]);
    int x = stoi(v[pos+1]), y = pos+2;
    for (int i = 0; i < x; ++i)
        y = max(y, recur(y, dep+1));
    return y;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> s;
    stringstream ss;
    ss.str(s);
    while (getline(ss, t, ','))
        v.push_back(t);
    /*
    for (string i : v)
        cout << i << '\n';
        */
    n = v.size();
    int y = 0;
    while (y < n) {
        //cout << y << '\n';
        y = recur(y, 0);
    }
    cout << m+1 << '\n';
    for (int i = 0; i <= m; ++i) {
        for (string j : d[i])
            cout << j << ' ';
        cout << '\n';
    }
	return 0;
}

