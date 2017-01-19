#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int ts; cin >> ts;
	for (int tc = 1; tc <= ts; ++tc){
		string s;
		cin.ignore();
		getline(cin, s);
		stringstream ss (s);
		vector<int> v;
		int a;
		while (ss >> a)
			v.push_back(a);
		sort(v.begin(), v.end());
		cout << "Case " << tc << ": " << v[v.size()/2] << '\n';
	}
return 0;}

