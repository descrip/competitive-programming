#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	for (int ts = 0; ts < t; ++ts){
		int n, m; cin >> n >> m;
		int lo = 0, hi = n+1, mid;
		while (lo + 1 < hi){
			mid = lo + (hi-lo)/2;
			if (0.5*(n*n - (n%mid)*pow(ceil((double)n/mid),2) - (mid-n%mid)*pow(floor((double)n/mid),2)) < m)
				lo = mid;
			else
				hi = mid;
		}
		cout << lo+1 << '\n';
	}
return 0;}
