#include <bits/stdc++.h>
using namespace std;

pair<int,string> solve(string a, string b, string c){
	multiset<char> s;
	for (char r : a)
		s.insert(r);
	string ans = "";
	bool ok = true;
	int cnt = 0;
	while (ok){
		for (int i = 0; i < b.size(); ++i){
			auto it = s.find(b[i]);
			if (it != s.end()){
				s.erase(it);
				if (i == b.size() - 1)
					ans += b, ++cnt;
			}
			else{
				for (int j = 0; j < i; ++j)
					s.insert(b[j]);
				ok = false;
				break;
			}
		}
	}
	ok = true;
	while (ok){
		for (int i = 0; i < c.size(); ++i){
			auto it = s.find(c[i]);
			if (it != s.end()){
				s.erase(it);
				if (i == c.size() - 1)
					ans += c, ++cnt;
			}
			else{
				for (int j = 0; j < i; ++j)
					s.insert(c[j]);
				ok = false;
				break;
			}
		}
	}
	for (char r : s)
		ans += r;
	return make_pair(cnt,ans);
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	string a, b, c; cin >> a >> b >> c;
	cout << max(solve(a,b,c),solve(a,c,b)).second << '\n';
return 0;}
