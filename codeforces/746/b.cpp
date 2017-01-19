#include <bits/stdc++.h>
using namespace std;

int n;
string s;

string recur(string s) {
    if (s.size() <= 1) return s;
    else return s[s.size()-2] + recur(s.substr(0, s.size()-2)) + s[s.size()-1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> n >> s;
    cout << recur(s) << '\n';
	return 0;
}

