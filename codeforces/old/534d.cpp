#include <vector>
#include <iostream>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	static vector<int> a[200001];
	for (int i = 1; i <= n; ++i){
		int x; cin >> x;
		a[x].push_back(i);
	}
	int x = 0;
	static int ans[200001];
	for (int i = 1; i <= n; ++i){
		while (x >= 0 && a[x].empty()) x -= 3;
		if (x < 0){
			cout << "Impossible\n"; return 0;
		}
		ans[i] = a[x].back();
		a[x++].pop_back();
	}
	cout << "Possible\n";
	for (int i = 1; i <= n; ++i)
		cout << ans[i] << " \n"[i==n];
return 0;}
