#include <bits/stdc++.h>
using namespace std;

int A, B;

int zmod(int a) {
    return ((a % 100) + 100) % 100;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    while (cin >> A >> B) {
        if (A == -1 && B == -1) break;
        cout << min(zmod(A - B), zmod(B - A)) << '\n';
    }
	return 0;
}

