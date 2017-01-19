//bad program that i salvaged from 28
//to speed up, add by interval

#include <bits/stdc++.h>
using namespace std;

const int LEN = 1001, LIM = 1000000000;

int main(){
	//ios_base::sync_with_stdio(0); cin.tie(0);

	static bool prime[LIM];
	fill_n(prime, LIM, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i*i < LIM; ++i)
		if (prime[i])
			for (int j = 2; i*j < LIM; ++j)
				prime[i * j] = false;

	int ans = 0, tot = 0, step = 2, last = 1, cnt = 0, i = 1;
	while (true){
		if (i - last == step){
			if (prime[i])
				++ans;
			last = i;
			++tot;
			cout << ans << ' ' << tot << ' ' << (double) ans / tot << '\n';
			if ((double) ans / tot < 0.1){
				cout << step << '\n';
				return 0;
			}
			++cnt;
			if (cnt == 4){
				step += 2;
				cnt = 0;
				i += step;
			}
		}
	}
return 0;}
