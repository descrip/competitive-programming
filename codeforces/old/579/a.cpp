#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	int ans = 1;
	while (n != 1){
		if (n % 2 == 0)
			n /= 2;
		else{
			n -= 1;
			++ans;
		}
	}
	cout << ans << '\n';
return 0;}
