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
	int n, m; cin >> n >> m;
	vector<bool> boys (n), girls (m);
	int b; cin >> b;
	for (int i = 0; i < b; ++i){
		int a; cin >> a;
		boys[a] = true;
	}
	int g; cin >> g;
	for (int i = 0; i < g; ++i){
		int a; cin >> a;
		girls[a] = true;
	}
	for (int j = 0; j < n*m; ++j)
		for (int i = 0; i < n*m; ++i)
			if (girls[i % m] == true || boys[i % n] == true)
				girls[i % m] = boys[i % n] = true;
	if (find(boys.begin(),boys.end(),false) == boys.end() && find(girls.begin(),girls.end(),false) == girls.end())
		cout << "Yes\n";
	else
		cout << "No\n";
return 0;}
