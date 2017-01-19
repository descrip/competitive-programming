#include <bits/stdc++.h>
using namespace std;

string S;
map<char, int> M;

int main() {
	cin >> S;
	if (S.size() % 2 == 1) {
		cout << -1 << '\n';
		return 0;
	}
	for (int i = 0; i < S.size(); ++i)
		M[S[i]]++;
	cout << (abs(M['L'] - M['R']) + abs(M['U'] - M['D']))/2 << '\n';
}

