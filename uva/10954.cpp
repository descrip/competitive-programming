#include <bits/stdc++.h>
using namespace std;

int N, A[5001];

int main() {
	while (true) {
		cin >> N;
		if (N == 0)
			break;
		priority_queue<int, vector<int>, greater<int> > pq;
		for (int i = 0; i < N; ++i) {
			int x; cin >> x;
			pq.push(x);
		}
		long long ans = 0;
		while (pq.size() > 1) {
			int a = pq.top(); pq.pop();
			int b = pq.top(); pq.pop();
			ans += a+b;
			pq.push(a+b);
		}
		cout << ans << '\n';
	}
}
