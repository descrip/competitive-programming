#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int d[10001];

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	while (true){
		int n; cin >> n;
		if (n == 0) break;
		for (int i = 1; i <= n; ++i) cin >> d[i];
		sort(d+1,d+n+1,greater<int>());
		if (accumulate(d+1,d+n+1,0) % 2 != 0) cout << "Not possible\n";
		else{
			for (int k = 1; k <= n; ++k){
				int r = 0;
				for (int i = k+1; i <= n; ++i) r += min(d[i],k);
				if (accumulate(d+1,d+k+1,0) > k*(k-1) + r){
					cout << "Not possible\n";
					break;
				}
				else if (k == n) cout << "Possible\n";
			}
		}
	}
return 0;}
