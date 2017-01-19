#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("empty.in", "r", stdin);
	freopen("empty.out", "w", stdout);
	int n, k; cin >> n >> k;
	static int v[3000000];
	for (int i = 0; i < k; ++i){
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		for (int j = 1; j <= y; ++j)
			v[((long long)a*j+b)%n] += x;
	}
	for (int i = 0; i < n-1; ++i)
		if (v[i] > 1){
			v[i+1] += v[i]-1;
			v[i] = 1;
		}
	if (v[n-1] > 1){
		v[0] += v[n-1]-1;
		v[n-1] = 1;
	}
	for (int i = 0; i < n-1; ++i)
		if (v[i] > 1){
			v[i+1] += v[i]-1;
			v[i] = 1;
		}
	for (int i = 0; i < n; ++i)
		if (v[i] == 0){
			cout << i << '\n';
			return 0;
		}
return 0;}
