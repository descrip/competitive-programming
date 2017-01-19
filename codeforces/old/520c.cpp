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
	string s; cin >> s;
	vector<int> cnt (4);
	for (int i = 0; i < s.size(); ++i){
		switch (s[i]){
			case 'A':
				++cnt[0];
				break;
			case 'C':
				++cnt[1];
				break;
			case 'G':
				++cnt[2];
				break;
			case 'T':
				++cnt[3];
				break;
		}
	}
	int best = 0, bestcnt = 0;
	for (int i = 0; i < 4; ++i) best = max(best,cnt[i]);
	for (int i = 0; i < 4; ++i)
		if (best == cnt[i])
			++bestcnt;
	ull ans = 1;
	for (int i = 0; i < s.size(); ++i)
		ans = (ans * bestcnt) % MOD;
	cout << ans << '\n';
return 0;}
