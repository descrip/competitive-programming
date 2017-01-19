#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	double best = 0;
	string name;
	for (int i = 0; i < n; ++i){
		double a; string b;
		cin >> b >> a;
		if (a > best){
			best = a;
			name = b;
		}
	}
	cout << name << '\n';
return 0;}
