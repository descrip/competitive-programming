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
	int t; cin >> t;
	for (int test = 0; test < t; ++test){
		string s; cin >> s;
		vector<vector<int>> dp (s.size()+1, vector<int> (s.size()+1));
		for (int len = 2; len <= s.size(); ++len){
			for (int pos = 0; pos <= s.size() - len; ++pos){
				if (s[pos] == s[pos+len-1])
					dp[pos][len] = dp[pos+1][len-2];
				else
					dp[pos][len] = min(dp[pos][len-1],dp[pos+1][len-1])+1;
			}
		}
		cout << dp[0][s.size()] << '\n';
	}
return 0;}
