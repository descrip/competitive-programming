#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	int ans = 0;
	while (N > 1){
		for (int i = N-1; i >= 1; --i)
			if (N % i == 0){
				ans += (N-i) / i;
				N -= i;
				break;
			}
	}
	cout << ans << '\n';
return 0;}

