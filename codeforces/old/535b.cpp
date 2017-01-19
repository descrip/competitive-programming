#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	bitset<32> b;
	string s; cin >> s;
	for (int i = 0; i < s.size(); ++i)
		b[s.size()-i-1] = (s[i] == '7' ? 1 : 0);
	b[s.size()] = 1;
	cout << b.to_ulong()-1 << '\n';
return 0;}
