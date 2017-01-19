#include <set>
#include <iostream>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	multiset<string> all;
	for (int y = 0; y < n; ++y){
		string s; cin >> s;
		all.insert(s);
	}
	int ans = 0;
	for (string i : all)
		ans = max(ans,(int)all.count(i));
	cout << ans << '\n';
return 0;}
