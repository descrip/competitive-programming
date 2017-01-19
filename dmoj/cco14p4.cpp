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
	int n, p, f; scan(n); scan(p);
	multiset<pii> v;
	for (int i = 1; i <= n; ++i){
		int a, b; scan(a); scan(b);
		if (i == p) f = a;
		else if (a >= b) v.insert({b,-a});
	}
	p = 1;
	int bestf = f, bestp = 1;
	while (true){
		if (v.empty() || (*v.begin()).first > f) break;
		f -= (*v.begin()).first + (*v.begin()).second;
		++p;
		if (f >= bestf){
			bestf = f;
			bestp = max(bestp,p);
		}
		v.erase(v.begin());
	}
	cout << bestf << '\n' << bestp << '\n';
return 0;}
