#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[25][25], T[25];

bool gao(int y) {
	int cnt = 0;
	for (int x = 0; x < M; ++x)
		if (A[y][x] != T[x])
			++cnt;
	return ((cnt == 2) || (cnt == 0));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int y = 0; y < N; ++y)
		for (int x = 0; x < M; ++x)
			cin >> A[y][x];
	for (int i = 0; i < M; ++i)
		T[i] = i+1;
	for (int i = 0; i < M; ++i)
		for (int j = i; j < M; ++j) {
			swap(T[i], T[j]);
			for (int y = 0; y < N; ++y) {
				if (!gao(y))
					break;
				else if (y == N-1) {
					cout << "YES\n";
					return 0;
				}
			}
			swap(T[i], T[j]);
		}
	cout << "NO\n";
	return 0;
}

