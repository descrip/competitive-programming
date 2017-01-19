#include <iostream>
using namespace std;

const int MOD = 1000000007;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int k; cin >> k;
	unsigned long long ans = 1;
	int len = 0;
	for (int i = 0; i < k; ++i){
		int cnt = 1, balls; cin >> balls;
		for (int j = len+1; j < len+balls; ++j)
			ans = (ans * j) / cnt++;
		len += balls;
		//cout << ans << ' ' << len << '\n';
	}
	cout << ans % MOD << '\n';
return 0;}
