//kek
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> a (n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int x = 1; x <= n; ++x){
		int ans = 0;
		for (int i = 0; i <= n-x; ++i)
			ans = max(ans,*min_element(a.begin()+i,a.begin()+i+x));
		cout << ans << ' ';
	}
	cout << '\n';
return 0;}
