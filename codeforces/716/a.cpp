#include <bits/stdc++.h>
using namespace std;

int N, C, A[100005];
int ans = 1;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> C;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	for (int i = 1; i < N; ++i)
		if (A[i] - A[i-1] > C) ans = 1;
		else ans++;
	cout << ans << '\n';
	return 0;
}

