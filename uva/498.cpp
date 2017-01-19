#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s, t;
	vector<int> c;
	while (getline(cin, s)){
		c.clear();
		getline(cin, t);
		//stringstream ss (s, ios_base::app | ios_base::out);
		stringstream ss (s);
		int x;
		while (ss >> x)
			c.push_back(x);
		stringstream ss2 (t);
		bool need = false;
		while (ss2 >> x){
			long long ans = c[0];
			for (int i = 1; i < c.size(); ++i)
				ans = ans * x + c[i];
			if (need)
				cout << ' ';
			need = true;
			cout << ans;
		}
		cout << '\n';
	}
return 0;}
