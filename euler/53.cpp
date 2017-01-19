#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	static unsigned long long ncr[101][101];
	for (int i = 0; i <= 100; ++i)
		ncr[i][0] = 1;
	int ans = 0;
	for (int i = 1; i <= 100; ++i)
		for (int j = 1; j <= 100; ++j){
			ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
			if (ncr[i][j] > 1000000)
				++ans;
		}
	cout << ans << '\n';
return 0;}

