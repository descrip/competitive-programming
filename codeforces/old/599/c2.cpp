#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> v (n), r (n), l (n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	l[0] = v[0];
	for (int i = 1; i < n; ++i)
		l[i] = max(l[i-1], v[i]);
	r[n-1] = v[n-1];
	for (int i = n-2; i >= 0; --i)
		r[i] = min(r[i+1], v[i]);
	set<int> ser;
	for (int i = 0; i < n; ++i)
		ser.insert(v[i]);
	map<int,int> m;
	for (int i = 0; i < n; ++i)
		m[v[i]] = i;
	int pos = 0, top = m[*ser.begin()], ans = 0;
	vector<int> tmp;
	while (pos != n){
		top = max(top, m[v[pos]]);
		tmp.clear();
		if (ser.count(v[pos]) != 0)
			for (auto it = ser.begin(); it != ser.find(v[pos]); ++it){
				top = max(top, m[*it]);
				tmp.push_back(*it);
				//cout << *it << '\n';
			}
		for (int i : tmp)
			ser.erase(i);
		//cout << pos << ' ' << top << ' ' << l[pos] << ' ' << r[pos+1] << '\n';
		if (pos >= top || (pos < n-1 && l[pos] == r[pos+1])){
			++ans;
			top = max(top, m[*ser.begin()]);
			//cout << pos << ' ' << top << ' ' << l[pos] << ' ' << r[pos+1] << '\n';
		}
		++pos;
	}
	cout << ans << '\n';
return 0;}

