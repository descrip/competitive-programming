#include <bits/stdc++.h>
using namespace std;

map<string, int> m;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	m["monday"] = 0;
	m["tuesday"] = 1;
	m["wednesday"] = 2;
	m["thursday"] = 3;
	m["friday"] = 4;
	m["saturday"] = 5;
	m["sunday"] = 6;

	vector<int> d = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	string s, t; cin >> s >> t;
	int a = m[s], b = m[t];

	for (int i = 0; i < d.size()-1; ++i) {
		if ((a + d[i]) % 7 == b) {
			cout << "YES\n";
			return 0;
		}
	}

	cout << "NO\n";

	return 0;
}

