#include <bits/stdc++.h>
using namespace std;

int Q;
bool A[75];
long long high_bit_mask = 1LL << (std::numeric_limits<long long>::digits - 1);

long long recur(long long b, int w) {
	long long bb = b;
	if (w == 0) return 1;
	else {
		long long ret = 1;
		for (int i = w-1; i >= 0; --i) {
			if (bb & (1 << i)) {
				bb &= ~high_bit_mask;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> Q;
	for (int q = 0; q < Q; ++q) {
		long long a, b, x; cin >> a >> b >> x;
		for (int i = 0; i < 64; ++i)
			A[i] = !(x & (1LL << i));	// we can
	}
}

