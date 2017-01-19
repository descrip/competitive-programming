#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int x;
	string s;
	vector<int> c;
	while (cin >> x){
		cin.ignore();
		c.clear();
		getline(cin, s);
		stringstream ss (s);
		int a;
		while (ss >> a)
			c.push_back(a);
		long long ans = c[0] * (c.size()-1);
		for (int i = 1; i < c.size()-1; ++i)
			ans = ans * x + c[i] * (c.size() - i - 1);
		cout << ans << '\n';
	}
return 0;}

