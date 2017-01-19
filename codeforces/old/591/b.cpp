#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	string s; cin >> s;
	static char c[97+27];
	for (int j = 'a'; j <= 'z'; ++j)
		c[j] = (char)j;
	for (int i = 0; i < m; ++i){
		char a, b; cin >> a >> b;
		for (char j = 'a'; j <= 'z'; ++j)
			if (c[j] == a)
				c[j] = b;
			else if (c[j] == b)
				c[j] = a;
	}
	//cout << c['p'] << '\n';
	for (int i = 0; i < n; ++i)
		s[i] = c[(int)s[i]];
	cout << s << '\n';
return 0;}
