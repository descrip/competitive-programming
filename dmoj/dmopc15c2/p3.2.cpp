#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long n, k; cin >> n >> k;
	long long t = 1; int ans = 0;
	while (t < n){
		t += min(t,k);
		++ans;
	}
	cout << ans << '\n';
return 0;}

