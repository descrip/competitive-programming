#include <bits/stdc++.h>
using namespace std;

int N;
pair<int,int> A[100005];
set<int> S;

bool zsort(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.first == b.first)
		return a.second < b.second;
	else return a.first > b.first;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> A[i].first >> A[i].second;
	sort(A, A+N, zsort);
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		//cout << A[i].second << '\n';
		S.insert(A[i].second);
		if (*S.rbegin() == A[i].second)
			++ans;
	}
	cout << ans << '\n';
}

