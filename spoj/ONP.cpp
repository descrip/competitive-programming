#include <bits/stdc++.h>
using namespace std;

string gao(string s){
	/*
	int it = s.find('^');
	if (it == string::npos)
		it = s.find('/');
	if (it == string::npos)
		it = s.find('*');
	if (it == string::npos)
		it = s.find('-');
	if (it == string::npos)
		it = s.find('+');
	if (it == string::npos)
		return s;
	*/
	return gao(s.substr(0,it)) + gao(s.substr(it+1)) + s[it];
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	for (int n = 0; n < N; ++n){
		string s; cin >> s;
		cout << gao(s) << '\n';
	}
return 0;}

