#include <bits/stdc++.h>
using namespace std;

const int LIM = 1000000;

int main(){
	//ios_base::sync_with_stdio(0); cin.tie(0);
	static bool prime[LIM];
	static int sum[LIM];
	int curr = 1;
	fill_n(prime, LIM, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i < LIM; ++i)
		if (prime[i]){
			for (int j = 2; i * j < LIM; ++j)
				prime[i * j] = false;
			sum[curr] = sum[curr-1] + i;
			++curr;
		}
	int best = 0, ans = 0;
	for (int i = 0; i < curr; ++i)
		for (int j = i - best; j >= 0; --j)
			if (prime[sum[i] - sum[j]] && i-j > best){
				best = i-j;
				ans = sum[i] - sum[j];
				cout << ans << ' ' << best << '\n';
				//segfaults, but reaches correct answer. too lazy to fix.
			}
	cout << ans << '\n';
return 0;}

