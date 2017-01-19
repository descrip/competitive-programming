#include <bits/stdc++.h>
using namespace std;

int N;
long long A[100001];

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> A[i];
	for (int i = 0; i < N-1; ++i) {
		A[i] += A[i+1];
		cout << A[i] << ' ';
	}
	cout << A[N-1] << '\n';
}

