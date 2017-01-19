#include <bits/stdc++.h>
using namespace std;

int main(){
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	static int v [100001][2];
	for (int i = 0; i < n; ++i)
		cin >> v[i][0];
	int ans = 0;
	while (true){
		bool ok = false;
		/*
		for (int i = 0; i < n; ++i)
			cout << v[i][ans%2] << ' ';
		cout << '\n';
		*/
		for (int i = ans; i < n-ans; ++i){
			v[i][1-ans%2] = 0;
			if (v[i][ans%2] != 0)
				ok = true;
			else continue;
			if (i == 0 || v[i-1][ans%2] == 0 || v[i+1][ans%2] == 0)
				v[i][1-ans%2] = 0;
			else if (v[i-1][ans%2] >= v[i][ans%2] && v[i+1][ans%2] >= v[i][ans%2])
				v[i][1-ans%2] = v[i][ans%2]-1;
			else if (v[i-1][ans%2] < v[i][ans%2] || v[i+1][ans%2] < v[i][ans%2])
				v[i][1-ans%2] = min(v[i+1][ans%2], v[i-1][ans%2]);
		}
		if (ok == false)
			break;
		++ans;
	}
	cout << ans << '\n';
return 0;}
