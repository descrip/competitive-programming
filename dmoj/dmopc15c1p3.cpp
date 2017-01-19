#include <bits/stdc++.h>
using namespace std;

char shift(char a, int r){
	return ((a-'a')+r)%26+'a';
}

int findShift(char a, char b){
	for (int i = 0; i < 26; ++i)
		if (shift(a,i) == b)
			return i;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s, t; cin >> s >> t;
	int ans = 0xfffffff;
	for (int i = 0; i < s.size()-t.size()+1; ++i){
		int r = findShift(t[0], s[i]);
		for (int j = 0; j < t.size(); ++j){
			if (shift(t[j], r) != s[i+j])
				break;
			else if (j == t.size()-1)
				ans = min(ans, r);
		}
	}
	cout << ans << '\n';
	for (int i = 0; i < s.size(); ++i)
		cout << shift(s[i], 26-ans);
	cout << '\n';
return 0;}
