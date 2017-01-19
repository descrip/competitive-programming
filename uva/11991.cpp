#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n, m;
	while (cin >> n >> m){
		vector<vector<int>> l (1000000, vector<int>());
		for (int i = 1; i <= n; ++i){
			int a; cin >> a;
			l[a].push_back(i);
		}
		for (int i = 0; i < m; ++i){
			int k, v; cin >> k >> v;
			if (l[v].size() < k) cout << "0\n";
			else cout << l[v][k-1] << '\n';
		}
	}
return 0;}
