#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> a (n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int v = a[n-1], pos = n-1;
	for (int i = 0; i < n; ++i){
		if (a[i] == v && i == 0)
			cout << a[i] << ' ';
		else if (a[i] == v && a[i-1] > v)
			cout << a[i-1] << ' ';
		else
			cout << a[i] << ' ';
	}
	cout << '\n';
	while (a[pos-1] > v){
		swap(a[pos-1],a[pos]);
		--pos;
		for (int i = 0; i < n; ++i){
			if (a[i] == v && i == 0)
				cout << a[i] << ' ';
			else if (a[i] == v && a[i-1] > v)
				cout << a[i-1] << ' ';
			else
				cout << a[i] << ' ';
		}
		cout << '\n';
	}
return 0;}
