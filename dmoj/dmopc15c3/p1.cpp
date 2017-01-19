#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<int> v (4), u, w (4), t;
	for (int i = 0; i < 4; ++i)
		cin >> v[i];
	w[0] = v[2];
	w[1] = v[3];
	w[2] = v[0];
	w[3] = v[1];
	u = v;
	t = w;
	sort(v.begin(), v.end());
	sort(w.begin(), w.end());
	cout << ((u != v && t != w) ? "YES\n" : "NO\n");
return 0;}

