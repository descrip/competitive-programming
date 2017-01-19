#include <bits/stdc++.h>
using namespace std; typedef unsigned long ul; typedef long long ll; typedef unsigned long long ull; typedef long double ld; typedef pair<int,int> pii;
#define __ << ' ' <<
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	set<pii> nodes;
	for (int i = 0; i < n; ++i){
		int a, b; cin >> a >> b;
		nodes.insert({a,b});
	}
	while (true){
		auto it = nodes.lower_bound(make_pair(1,-1));
		if (it->first == nodes.end()) break;
		it->first = 0;
	}
return 0;}
