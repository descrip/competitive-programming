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
	int n; cin >> n;
	vector<long> t (n), s (n);
	for (int i = 0; i < n; ++i) cin >> t[i];
	for (int i = 0; i < n; ++i) cin >> s[i];
	sort(t.begin(),t.end());
	sort(s.begin(),s.end(),greater<long>());
	long sum = 0;
	for (int i = 0; i < n; ++i) sum += t[i] * s[i];
	cout << sum << '\n';
return 0;}
