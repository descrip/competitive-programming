#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	vector<int> a (N), b (N);
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	for (int i = 0; i < N; ++i)
		cin >> b[i];
	int A = 0, B = 0;
	for (int i = 0; i < N; ++i)
		if (a[i] > b[i]) ++A;
		else if (a[i] < b[i]) ++B;
	cout << A << ' ' << B << '\n';
	if (A > B)
		cout << "Xyene\n";
	else if (A < B)
		cout << "FatalEagle\n";
	else cout << "Tie\n";
return 0;}

