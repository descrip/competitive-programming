#include <bits/stdc++.h>
using namespace std;

int n, k;
bool ok = false;
char a[101];

void recur(int x) {
	if (!(0 <= x && x < n))
		return;
	else if (a[x] == '#')
		return;
	else if (a[x] == 'T')
		ok = true;
	a[x] = '#';
	recur(x+k);
	recur(x-k);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		if (a[i] == 'G')
			recur(i);
	cout << (ok ? "YES" : "NO") << '\n';
	return 0;
}
