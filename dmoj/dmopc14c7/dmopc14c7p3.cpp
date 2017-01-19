#include <set>
#include <iostream>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n, l, r; cin >> n >> l >> r;
	set<int> left, right;
	for (int i = 0; i < l; ++i){
		int a; cin >> a;
		left.insert(a);
	}
	for (int i = 0; i < r; ++i){
		int a; cin >> a;
		right.insert(a);
	}
	int ans = 0;
	for (auto it = left.begin(); it != left.end(); ++it)
		if (right.count(*it) != 0)
			++ans;
	cout << n - ans << '\n';
return 0;}
