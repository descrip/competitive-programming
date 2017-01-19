#include <bits/stdc++.h>
using namespace std;

// It seems that Setu did not recover and passed away in April 2012. ):
// https://fo-fo.facebook.com/groups/HelpSetuSaveALife/

int main() {
	int T; cin >> T;
	long long sum = 0;
	for (int i = 0; i < T; ++i) {
		string s; cin >> s;
		if (s == "donate") {
			int x; cin >> x;
			sum += x;
		}
		else cout << sum << '\n';
	}
}
