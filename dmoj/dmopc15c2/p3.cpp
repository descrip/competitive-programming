#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long n, k; cin >> n >> k;
	long long ans = log2(min(n,k))+1;
	long long t = (1<<ans);
	//cout << ans << ' ' << t << '\n';
	if (n > k)
		cout << ans + (n - t)/k + ((n - t) % k != 0) << '\n';
	else
		cout << ans << '\n';
return 0;}

