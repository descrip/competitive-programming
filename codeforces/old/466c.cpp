#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	static int a[500000];
	long long sum = 0;
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		sum += a[i];
	}
	long long ans = 0;
	if (sum % 3 == 0){
		long long tmp = 0;
		long long cnt = 0;
		for (int i = 0; i < n; ++i){
			tmp += a[i];
			if (i < n-1){
				if (tmp == 2*sum/3)
					ans += cnt;
				if (tmp == sum/3)
					++cnt;
			}
		}
	}
	cout << ans << '\n';
return 0;}
