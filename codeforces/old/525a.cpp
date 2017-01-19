#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	int cnt = 0;
	multiset<char> keys;
	for (int i = 0; i < 2*n-2; ++i){
		if (i % 2 == 0) keys.insert(s[i]);
		else{
			if (keys.count((char)(s[i]+32)) > 0)
				keys.erase(keys.find((char)(s[i]+32)));
			else
				++cnt;
		}
	}
	cout << cnt << '\n';
return 0;}
