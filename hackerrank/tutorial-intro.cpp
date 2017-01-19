#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int v, n; cin >> v >> n;
	for (int i = 0; i < n; ++i){
		int a; cin >> a;
		if (a == v){
			cout << i << '\n';
			return 0;
		}
	}
return 0;}
