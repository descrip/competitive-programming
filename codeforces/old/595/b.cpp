#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k; cin >> n >> k;
	vector<long long> a (n/k), b (n/k), cnt (n/k);
	for (int i = 0; i < n/k; ++i)
		cin >> a[i];
	for (int i = 0; i < n/k; ++i)
		cin >> b[i];
	
	for (int i = 0; i < n/k; ++i){
		cnt[i] = floor((pow(10,k)-1) / a[i]) + 1;
		long long low = ceil(b[i]*pow(10,k-1)/a[i]) * a[i];
		long long high = floor(((b[i]+1)*pow(10,k-1)-1)/a[i]) * a[i];
		//cout << a[i] << ' ' << low << ' ' << high << ' ' << (long long)ceil((high - low) / (double)a[i]) + 1 << '\n';
		if (high < low)
			continue;
		else if (low == high)
			cnt[i]--;
		else
			cnt[i] -= ceil((high-low)/(double)a[i]) + 1;
		//cout << cnt[i] << '\n';
	}
	
	long long ans = 1;
	for (long long i : cnt)
		ans = (ans * i) % MOD;
	cout << ans << '\n';
return 0;}

