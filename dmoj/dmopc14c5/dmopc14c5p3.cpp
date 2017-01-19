#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main(){
	int n; cin >> n;
	vector<int> v (n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	int best = 0;
	int curr = 0;
	for (int i = 0; i < n-1; ++i){
		if (curr == 0){
			if (abs(v[i] - v[i+1]) <= 2) ++curr;
		}
		else{
			if (!(abs(v[i] - v[i+1]) <= 2)){
				best = max(best,curr+1);
				curr = 0;
			}
			else ++curr;
		}
		//cout << i << ' ' << curr << '\n';
	}
	best = max(best,curr+1);
	cout << best << '\n';
return 0;}
