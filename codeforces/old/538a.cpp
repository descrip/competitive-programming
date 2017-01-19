#include <iostream>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	/*
	if (s.find("CODEFORCES") != string::npos){
		cout << "YES\n"; return 0;
	}
	*/
	for (int i = 0; i < s.size(); ++i)
		for (int j = i; j <= s.size(); ++j){
			if (s.substr(0,i) + s.substr(j,s.size()-j) == "CODEFORCES"){
				cout << "YES\n";
				return 0;
			}
		}
	cout << "NO\n";
return 0;}
