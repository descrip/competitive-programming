#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	int ans = 0;
	for (char c : s)
		ans = max(ans,c-'0');
	cout << ans << '\n';
	for (int i = 0; i < ans; ++i){
		string t = "";
		for (int j = 0; j < s.size(); ++j){
			if (s[j] - '0' > 0){
				t += '1';
				--s[j];
			}
			else t += '0';
		}
		cout << atoi(t.c_str()) << ' ';
	}
return 0;}
