// {{{ Headers 
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>//#include <cstdio>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std; typedef unsigned long ul; typedef long long ll; typedef unsigned long long ull; typedef long double ld; typedef pair<int,int> pii;
#define pb push_back
#define __ << ' ' <<
#define MOD 1000000007
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
// }}}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int w = 0, b = 0;
	map<char,int> mb, mw;
	mb['q'] = 9;
	mb['r'] = 5;
	mb['b'] = 3;
	mb['n'] = 3;
	mb['p'] = 1;
	mb['k'] = 0;
	mw['Q'] = 9;
	mw['R'] = 5;
	mw['B'] = 3;
	mw['N'] = 3;
	mw['P'] = 1;
	mw['K'] = 0;
	for (int y = 0; y < 8; ++y){
		for (int x = 0; x < 8;++x){
			char c; cin >> c;
			if (c == '.') continue;
			if (97 <= c) b += mb[c];
			else w+=mw[c];
		}
	}
	if (b == w) cout << "Draw\n";
	else cout << (b > w ? "Black\n" : "White\n");
return 0;}
