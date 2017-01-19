#include <bits/stdc++.h>
using namespace std;

long long N, A[501][501];

int main() {
	cin >> N;
	for (int y = 0; y < N; ++y)
		for (int x = 0; x < N; ++x)
			cin >> A[y][x];

	if (N == 1) {
		cout << "374\n";
		return 0;
	}

	bool ok = true;
	long long sum1 = -1, sum2 = -1;

	for (int y = 0; y < N; ++y) {
		bool zero = false;
		long long curr = 0;
		for (int x = 0; x < N; ++x) {
			curr += A[y][x];
			if (A[y][x] == 0)
				zero = true;
		}
		if (!zero) {
			if (sum1 == -1 || sum1 == curr)
				sum1 = curr;
			else ok = false;
		}
		else if (zero) {
			if (sum2 == -1 || sum2 == curr)
				sum2 = curr;
			else ok = false;
		}
	}

	for (int x = 0; x < N; ++x) {
		bool zero = false;
		long long curr = 0;
		for (int y = 0; y < N; ++y) {
			curr += A[y][x];
			if (A[y][x] == 0)
				zero = true;
		}
		if (!zero) {
			if (sum1 == -1 || sum1 == curr)
				sum1 = curr;
			else ok = false;
		}
		else if (zero) {
			if (sum2 == -1 || sum2 == curr)
				sum2 = curr;
			else ok = false;
		}
	}

	bool zero = false;
	long long curr = 0;
	for (int i = 0; i < N; ++i) {
		curr += A[i][i];
		if (A[i][i] == 0)
			zero = true;
	}
	if (!zero) {
		if (sum1 == -1 || sum1 == curr)
			sum1 = curr;
		else ok = false;
	}
	else if (zero) {
		if (sum2 == -1 || sum2 == curr)
			sum2 = curr;
		else ok = false;
	}

	zero = false;
	curr = 0;
	for (int i = 0; i < N; ++i) {
		curr += A[i][N-i-1];
		if (A[i][N-i-1] == 0)
			zero = true;
	}
	if (!zero) {
		if (sum1 == -1 || sum1 == curr)
			sum1 = curr;
		else ok = false;
	}
	else if (zero) {
		if (sum2 == -1 || sum2 == curr)
			sum2 = curr;
		else ok = false;
	}

	if (!ok || sum1 <= sum2) cout << -1 << '\n';
	else cout << sum1 - sum2 << '\n';
}

