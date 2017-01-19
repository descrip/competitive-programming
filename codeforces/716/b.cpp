#include <bits/stdc++.h>
using namespace std;

string S;
int A[300];

bool check() {
	for (int i = 'A'; i <= 'Z'; ++i)
		if (A[i] > 1) return false;
	return true;
}

void fill(int pos) {
	queue<char> Q;
	for (int i = 'A'; i <= 'Z'; ++i)
		if (A[i] == 0)
			Q.push((char)i);
	for (int i = pos-25; i <= pos; ++i)
		if (S[i] == '?') {
			S[i] = Q.front();
			Q.pop();
		}
	for (int i = 0; i < S.size(); ++i)
		if (S[i] == '?')
			S[i] = 'A';
	cout << S << '\n';
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> S;
	if (S.size() < 26) {
		cout << -1 << '\n';
		return 0;
	}
	for (int i = 0; i < 26; ++i)
		A[S[i]]++;
	if (check()) fill(25);
	for (int i = 26; i < S.size(); ++i) {
		A[S[i-26]]--;
		A[S[i]]++;
		if (check()) fill(i);
	}
	cout << -1 << '\n';
	return 0;
}

