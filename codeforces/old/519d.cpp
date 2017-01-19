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
	map<char,int> ap;
	for (int i = 0; i < 26; ++i){
		int a; cin >> a;
		ap[(char)(i+97)] = a;
	}
	string s; cin >> s;
	vector<ull> ps (s.size());
	ps[0] = ap[s[0]];
	for (int i = 1; i < s.size(); ++i)
		ps[i] = ps[i-1] + ap[s[i]];
	ull cnt = 0;
	multimap<pair<ull,char>,int> look;
	look.insert({{ps[0],s[0]},1});
	for (int i = 1; i < s.size(); ++i){
		auto it = look.find(make_pair(ps[i-1],s[i]));
		if (it != look.end())
			cnt += it->second;
		it = look.find(make_pair(ps[i],s[i]));
		if (it == look.end())
			look.insert({{ps[i],s[i]},1});
		else
			++it->second;
	}
	cout << cnt << '\n';
return 0;}
