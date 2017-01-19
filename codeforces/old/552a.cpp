#include <iostream>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	long long ans = 0;
	int n; cin >> n;
	for (int i = 0; i < n; ++i){
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		ans += (x2-x1+1) * (y2-y1+1);
	}
	cout << ans << '\n';
return 0;}
