#include <vector>
#include <iostream>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> a (n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	vector<int> b (n);
	for (int i = 0; i < n; ++i)
		b[i] = i;
	for (int i = 0; i < 2*n; ++i){
		for (int j = 0; j < n; ++j){
			if (j % 2 == 0)
				a[j] = (a[j] + 1) % n;
			else
				a[j] = ((a[j] - 1) % n + n) % n;
		}
		if (a == b){
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
return 0;}
