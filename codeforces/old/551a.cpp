#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> a (n), b (n);
	set<int> s;
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		s.insert(a[i]);
	}
	int cnt = 1;
	for (auto it = s.rbegin(); it != s.rend(); ++it){
		int tot = 0;
		for (int i = 0; i < n; ++i)
			if (a[i] == *it)
				b[i] = cnt, ++tot;
		cnt += tot;
	}
	for (int i = 0; i < n; ++i)
		cout << b[i] << ' ';
	cout << '\n';
return 0;}
