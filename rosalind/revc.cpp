#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	reverse(s.begin(), s.end());
	for (int i = 0; i < s.size(); ++i){
		if (s[i] == 'G')
			s[i] = 'C';
		else if (s[i] == 'C')
			s[i] = 'G';
		else if (s[i] == 'A')
			s[i] = 'T';
		else if (s[i] == 'T')
			s[i] = 'A';
	}
	cout << s << '\n';
return 0;}

