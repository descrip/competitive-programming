#include <bits/stdc++.h>
using namespace std; typedef unsigned long ul; typedef long long ll; typedef unsigned long long ull; typedef long double ld; typedef pair<int,int> pii;
#define __ << ' ' <<
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	string s, t; cin >> s >> t;
	multiset<char> look;
	for (char c : t) look.insert(c);
	int yay = 0, whoops = 0;
	for (int i = 0; i < s.size(); ++i){
		if (look.count(s[i]) > 0){
			++yay;
			look.erase(look.find(s[i]));
			s[i] = '.';
		}
	}
	for (int i = 0; i < s.size(); ++i){
		if (s[i] == '.') continue;
		multiset<char>::iterator it;
		if (s[i] >= 97) it = look.find(s[i]-32);
		else it = look.find(s[i]+32);
		if (it != look.end()){
			look.erase(it);
			++whoops;
		}
	}
	cout << yay __ whoops << '\n';
return 0;}
