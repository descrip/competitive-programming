// {{{ Headers 
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>//#include <cstdio>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std; typedef long long ll; typedef unsigned long long ull; typedef long double ld; typedef pair<int,int> pii;
#define pb push_back
#define __ << ' ' <<
#define MOD 1000000007
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
// }}}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	set<ull> mem;
	int n, m; cin >> n >> m;
	string s, t;
	hash<string> h1; hash<ull> h2;
	for (int i = 0; i < n; ++i){
		cin >> s;
		t = s;
		for (int j = 0; j < s.length(); ++j)
			for (int k = 0; k < 3; ++k)
				mem.insert(h2(h1(s)));
	}
	char c;
	for (int i = 0; i < m; ++i){
		cin >> s;
		for (int i = 0; i < s.length(); ++i){
			for (int j = 0; j < 3; ++j){
				if (97 + j != s[i]){
					c = s[i];
					s[i] = 97+j;
					if (mem.count(h2(h1(s))) == 1){
						cout << "YES\n";
						goto breakout;
					}
					s[i] = c;
				}
			}
		}
		cout << "NO\n";
breakout:
		continue;
	}
return 0;}
