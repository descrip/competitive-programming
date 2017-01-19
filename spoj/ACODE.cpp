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
	while (true){
		string s; cin >> s;
		if (s == "0") break;
		vector<ull> dp (s.size());
		dp[0] = 1;
		for (int i = 1 ; i < s.size(); ++i){
			if (s[i] == '0'){
				if (s[i-1] - '0' <= 2 && s[i-1] != '0'){
					if (i == 1)
						dp[i] = 1;
					else
						dp[i] = dp[i-2];
				}
				else{
					dp[s.size()-1] = 0;
					break;
				}
			}
			else{
				dp[i] = dp[i-1];
				if ((s[i-1] - '0') * 10 + s[i] - '0' <= 26){
					if (i == 1)
						dp[i] = 2;
					else if (s[i-1] == '0')
						dp[i] = dp[i-1];
					else
						dp[i] += dp[i-2];
				}
			}
		}
		cout << dp[s.size()-1] << '\n';
	}
return 0;}
