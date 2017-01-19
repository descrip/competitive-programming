#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	map<string,int> m;
	for (int i = 0; i < n; ++i){
		string s; cin >> s;
		m[s]; ++m[s];
		cin.ignore(256,'\n');
	}
	for (auto it = m.begin(); it != m.end(); ++it)
		cout << it->first << ' ' << it->second << '\n';
return 0;}
