#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	static int a[256];
	for (int i = 0; i < s.size(); ++i)
		++a[(int)s[i]];
	cout << a['A'] << ' ' << a['C'] << ' ' << a['G'] << ' ' << a['T'] << '\n';
return 0;}

