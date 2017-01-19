#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int d[1010];

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	for (int test = 0; test < t; ++test){
		memset(d,0,sizeof d);
		int n; cin >> n;
		for (int i = 1; i <= n; ++i) cin >> d[i];
		if (n == 0 || (n == 1 && d[n] == 0)){
			cout << "Yes\n"; continue;
		}
		sort(d+1,d+n+1,greater<int>());
		if (accumulate(d+1,d+n+1,0) % 2 != 0) cout << "No\n";
		else{
			for (int k = 1; k <= n; ++k){
				int r = 0;
				for (int i = k+1; i <= n; ++i) r += min(d[i],k);
				cout << k << ' ' << accumulate(d+1,d+k+1,0) << '\n';
				if (accumulate(d+1,d+k+1,0) > k*(k-1) + r){
					cout << "No\n"; break;
				}
				else if (k == n-1) cout << "Yes\n";
			}
		}
	}
return 0;}
