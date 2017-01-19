#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main(){
	int n; cin >> n;
	int best = 0;
	for (int i = 0; i < n; ++i){
		int a, b; cin >> a >> b;
		best = max(best,b-a);
	}
	cout << best << '\n';
return 0;}
