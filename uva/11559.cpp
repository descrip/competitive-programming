#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n, b, h, w;
	while (cin >> n >> b >> h >> w){
		int best = 0xFFFFFFF;
		for (int i = 0; i < h; ++i){
			int p; cin >> p;
			for (int j = 0; j < w; ++j){
				int a; cin >> a;
				if (a >= n && n * p <= b)
					best = min(best,n*p);
			}
		}
		if (best == 0xFFFFFFF) cout << "stay home\n";
		else cout << best << '\n';
	}
return 0;}
