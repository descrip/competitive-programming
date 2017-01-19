#include <iostream>
using namespace std;

const int MOD = 1000000007;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	static int x[10], d[10], dp[301][10][101];
	for (int ts = 0; ts < t; ++ts){
		int n, m; cin >> n >> m;
		for (int i = 0; i < n; ++i)
			cin >> x[i];
		for (int i = 0; i < n; ++i)
			cin >> d[i];
		fill(dp[0][0][0],301*10*101,-1);
		
	}
return 0;}
