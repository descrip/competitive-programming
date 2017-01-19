#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	s = "00" + s;
	for (int i = 0; i < s.size(); ++i)
		for (int j = i+1; j < s.size(); ++j)
			for (int k = j+1; k < s.size(); ++k)
				if ((100*(s[i]-'0') + 10*(s[j]-'0') + s[k]-'0') % 8 == 0){
					cout << "YES\n" << (100*(s[i]-'0') + 10*(s[j]-'0') + s[k]-'0') << '\n';
					return 0;
				}
	cout << "NO\n";
return 0;}
