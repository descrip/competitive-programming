#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	vector<int> V (N);
	for (int i = 0; i < N; ++i)
		cin >> V[i];
	sort(V.begin(), V.end());
	vector<long long> S (5000);
	for (int i = 0; i < N; ++i)
		for (int j = i+1; j < N; ++j)
			++S[V[j]-V[i]];
	for (int i = 1; i < 5000; ++i)
		S[i] += S[i-1];

	/*
	for (int i = 1; i <= 10; ++i)
		cout << i << ' ';
	cout << '\n';
	for (int i = 1; i <= 10; ++i)
		cout << S[i] << ' ';
	cout << '\n';
	*/

	long double ans = 0;
	for (int i = 1; i < 5000; ++i)
		for (int j = 1; j < i; ++j){
			//cout << i << ' ' << j << ' ' << S[i-j-1] << '\n';
			ans += (S[i] - S[i-1]) * (S[j] - S[j-1]) * S[i-j-1];
		}
	//cout << ans << '\n';
	long double div = N * (N-1) / 2;
	cout << fixed << setprecision(9) << ans / (div * div * div) << '\n';
return 0;}

