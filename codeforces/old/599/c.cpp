#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> v (n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	map<int,int> m;
	for (int i = 0; i < n; ++i)
		m[v[i]] = i;
	/*
	set<int> ser;
	for (int i = 0; i < n; ++i)
		ser.insert(v[i]);
		*/
	int pos = 0, top = 0, ans = 0;
	/*
	while (pos < n-1 && v[pos+1] >= v[pos]){
		++pos;
		++ans;
	}
	while (!ser.empty()){
		int a = *ser.begin();
		ser.erase(a);
		if (m[a] < pos)
			continue;
		else{
			pos = m[a];
			++ans;
		}
	}
	*/
	while (pos != n){
		top = max(top, m[pos]);
		if (pos >= top)
			++ans;
		++pos;
	}
	cout << ans << '\n';
return 0;}

