#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	vector<long long> v (N);
	long long tot = 0;
	for (int i = 0; i < N; ++i){
		cin >> v[i];
		tot += v[i];
	}
	if (tot % N != 0){
		cout << "Impossible\n";
		return 0;
	}
	long long ans = 0;
	for (int i = 0; i < N; ++i)
		ans += abs(v[i] - tot / N);
	cout << ans/2 << '\n';
return 0;}

