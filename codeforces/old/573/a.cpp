#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> v (n);
	vector<vector<int>> p (2);
	for (int i = 0; i < n; ++i){
		cin >> v[i];
		int a = v[i];
		while (a%2 == 0)
			a /= 2;
		while (a%3 == 0)
			a /= 3;
		for (int j = 5; j*j <= a; j += 2)
			while (a%j == 0){
				p[i!=0].push_back(j);
				a /= j;
			}
		if (a > 2)
			p[i!=0].push_back(a);
		if (p[i!=0] != p[0]){
			cout << "No\n";
			return 0;
		}
		p[1].clear();
	}
	cout << "Yes\n";
return 0;}
