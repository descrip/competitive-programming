#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s, t; cin >> s >> t;
	for (int i = 0; i < s.size(); ++i){
		int has = -1, ast = -1;
		for (int j = 0; j < t.size(); ++j)
			if (t[j] == s[i])
				has = j;
			else if (t[j] == '*')
				ast = j;
		if (has != -1)
			t[has] = 'X';
		else if (ast != -1)
			t[ast] = 'X';
		else{
			cout << "N\n";
			return 0;
		}
	}
	cout << "A\n";
return 0;}

