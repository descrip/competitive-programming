#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a, b; cin >> a >> b;
	int n = b+1;
	long long ans = 0;
	while ((n/b)/(double)(n%b) <= (b-1)*a){
		cout << n << '\n';
		ans += n;
		n += b;
	}
	cout << ans << '\n';
return 0;}
