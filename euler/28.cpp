#include <bits/stdc++.h>
using namespace std;

const int LEN = 1001;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long ans = 1;
	int step = 2, last = 1, cnt = 0;
	for (int i = 3; i <= LEN*LEN; ++i)
		if (i - last == step){
			ans += i;
			last = i;
			++cnt;
			if (cnt == 4){
				step += 2;
				cnt = 0;
			}
		}
	cout << ans << '\n';
return 0;}

