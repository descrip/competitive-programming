#include <set>
#include <iostream>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	set<string> all;
	for (int i = 0; i <= s.size(); ++i){
		for (char j = 'a'; j != 'z'+1; ++j){
			string t = s.substr(0,i) + j + s.substr(i,s.size()-i);
			all.insert(t);
		}
	}
	cout << all.size() << '\n';
return 0;}
