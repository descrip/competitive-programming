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
	int n; cin >> n;
	vector<int> v;
	for (int i = 0; i < n; ++i){
		char c; cin >> c;
		int a = c - '0';
		if (a == 0) continue;
		else if (a == 1) continue;
		else if (a == 2) v.pb(2);
		else if (a == 3) v.pb(3);
		else if (a == 4){
			v.pb(3); v.pb(2); v.pb(2);
		}
		else if (a == 5) v.pb(5);
		else if (a == 6){
			v.pb(5); v.pb(3);
		}
		else if (a == 7) v.pb(7);
		else if (a == 8){
			v.pb(7); 
			v.pb(2);
			v.pb(2);
			v.pb(2);
		}
		else if (a == 9){
			v.pb(7); v.pb(3); v.pb(3); v.pb(2);
		}
	}
	sort(v.begin(),v.end(),greater<int>());
	for (int i : v)
		cout << i;
	cout << '\n';
return 0;}
