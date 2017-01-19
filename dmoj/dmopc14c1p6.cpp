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

int fact[6] = {1,1,2,6,24,120};

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	vector<vector<pii>> v = {
		{{1,1}},
		{{1,1}},
		{{1,2},{2,1}},
		{{1,3},{3,6},{6,1}},
		{{1,4},{4,12},{6,6},{12,12},{24,1}},
		{{1,5},{5,20},{10,20},{20,30},{30,30},{60,20},{120,1}}};
	int k; ll n; cin >> k >> n;
	ld het = fact[k] / pow(k,k);
	if (n > 50)
		het = 10e-10;
	else
		het = pow(het,n);
	ld pn = het / fact[k];
	for (int i = 0; i < v[k].size(); ++i)
		for (int j = 0; j < v[k][i].second; ++j)
			cout << setprecision(11) << fixed << v[k][i].first * pn << '\n';
return 0;}
