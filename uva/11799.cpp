#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	for (int test = 0; test < t; ++test){
		int n; cin >> n;
		int best = 0;
		for (int i = 0; i < n; ++i){
			int a; cin >> a;
			best = max(best,a);
		}
		printf("Case %d: %d\n",test+1,best);
	}
return 0;}
