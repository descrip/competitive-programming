#include <bits/stdc++.h>
using namespace std;

int N;
char A[1001][5];

int main() {
	cin >> N;
	for (int y = 0; y < N; ++y)
		for (int x = 0; x < 5; ++x)
			cin >> A[y][x];
	bool ok = false;
	for (int y = 0; y < N; ++y) {
		if (A[y][0] == 'O' && A[y][1] == 'O')
			A[y][0] = A[y][1] = '+';
		else if (A[y][3] == 'O' && A[y][4] == 'O')
			A[y][3] = A[y][4] = '+';
		if (A[y][0] == '+' || A[y][3] == '+') {
			ok = true;
			break;
		}
	}
	cout << (ok ? "YES" : "NO") << '\n';
	if (ok)
		for (int y = 0; y < N; ++y) {
			for (int x = 0; x < 5; ++x)
				cout << A[y][x];
			cout << '\n';
		}
}

