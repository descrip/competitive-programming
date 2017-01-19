#include <iostream>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int v1, v2, d, t; cin >> v1 >> v2 >> t >> d;
	long long ans = 0;
	for (int i = 0; i < t; ++i)
		ans += min(v1+d*i,v2+d*(t-i-1));
	cout << ans << '\n';
return 0;}
