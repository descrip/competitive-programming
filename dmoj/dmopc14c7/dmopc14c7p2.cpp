#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n, mini = 0, maxi = 0; cin >> n;
	vector<int> a (n);
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		if (a[i] > a[maxi]) maxi = i;
		if (a[i] < a[mini]) mini = i;
	}
	vector<int> b = a;
	if (maxi < mini){
		cout << "unknown\n";
		return 0;
	}
	sort(b.begin()+mini,b.begin()+maxi);
	if (b != a) cout << "unknown\n";
	else cout << a[maxi] - a[mini] << '\n';
return 0;}
