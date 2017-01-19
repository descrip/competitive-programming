#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	for (int i = 0; i < s.size(); ++i)
		if (s[i] == 'T')
			s[i] = 'U';
	cout << s << '\n';
return 0;}

