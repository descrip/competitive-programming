#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> v (3);
	for (int i = 0; i < 3; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());
	int a = v[0], b = v[1], c = v[2];
	multiset<int> s;
	for (int i = 0; i < n; ++i){
		int x; cin >> x;
		s.insert(x);
	}
	if (*s.rbegin() > a+b+c){
		cout << "-1\n";
		return 0;
	}
	int ans = 0;
	while (s.size() != 0 && *s.rbegin() > b+c){
		auto it = s.end();
		s.erase(--it);
		++ans;
	}
	//cout << "1 " << ans << '\n';
	while (s.size() != 0 && *s.rbegin() > a+c){
		auto it = s.end();
		s.erase(--it);
		++ans;
		auto it2 = s.upper_bound(a);
		if (s.size() != 0 && it2 != s.begin())
			s.erase(--it2);
	}
	//cout << "2 " << ans << '\n';
	while (s.size() != 0 && *s.rbegin() > b+a){
		auto it = s.end();
		s.erase(--it);
		++ans;
		auto it2 = s.upper_bound(b);
		if (s.size() != 0 && it2 != s.begin())
			s.erase(--it2);
	}
	//cout << "3 " << ans << '\n';
	while (s.size() != 0 && *s.rbegin() > c){
		auto it = s.end();
		s.erase(--it);
		++ans;
		auto it2 = s.upper_bound(c);
		if (s.size() != 0 && it2 != s.begin())
			s.erase(--it2);
	}
	//cout << "4 " << ans << '\n';
	while (s.size() != 0 && *s.rbegin() > b){
		auto it = s.end();
		s.erase(--it);
		++ans;
		auto it2 = s.upper_bound(b);
		if (s.size() != 0 && it2 != s.begin())
			s.erase(--it2);
		auto it3 = s.upper_bound(a);
		if (s.size() != 0 && it3 != s.begin())
			s.erase(--it3);
	}
	//cout << "5 " << ans << '\n';
	while (s.size() != 0 && *s.rbegin() > a){
		auto it = s.end();
		s.erase(--it);
		++ans;
		auto it2 = s.upper_bound(c);
		if (s.size() != 0 && it2 != s.begin())
			s.erase(--it2);
		auto it3 = s.upper_bound(a);
		if (s.size() != 0 && it3 != s.begin())
			s.erase(--it3);
	}
	//cout << "6 " << ans << '\n';
	cout << ans+(int)ceil(s.size()/3.0) << '\n';
return 0;}


