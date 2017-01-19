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

#define dpa(v) dp[v[0]][v[1]][v[2]][v[3]]

int poss[5][4] = {
	{2,1,0,2}, {1,1,1,1}, {0,0,2,1}, {0,3,0,0}, {1,0,0,1}
};
int dp[31][31][31][31];
int v[4];

bool recur(){
	if (dpa(v) > 0)
		return dpa(v) == 2 ? true : false;
	for (int i = 0; i < 5; ++i){
		for (int j = 0; j < 4; ++j){
			if (poss[i][j] > v[j])
				break;
			else if (j == 3){
				for (int k = 0; k < 4; ++k)
					v[k] -= poss[i][k];
				bool ok = false;
				if (!recur())
					ok = true;
				for (int k = 0; k < 4; ++k)
					v[k] += poss[i][k];
				if (ok){
					dpa(v) = 2;
					return true;
				}
			}
		}
	}
	dpa(v) = 1;
	return false;
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n; scan(n);
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < 4; ++j)
			scan(v[j]);
		cout << (recur() == true ? "Patrick\n" : "Roland\n");
	}
return 0;}
