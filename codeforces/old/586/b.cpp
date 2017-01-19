#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	int ans1 = 0xfffffff, ans2 = 0xfffffff;
	vector<int> a1 (n), a2 (n), b(n);
	for (int i = 1; i < n; ++i){
		cin >> a1[i];
		a1[i] += a1[i-1];
	}
	for (int i = 0; i < n-1; ++i)
		cin >> a2[i];
	for (int i = n-2; i >= 0; --i)
		a2[i] += a2[i+1];
	for (int i = 0; i < n; ++i)
		cin >> b[i];
	for (int i = 0; i < n; ++i){
		int tmp = a2[i] + b[i] + a1[i];
		if (tmp <= ans1){
			ans2 = ans1;
			ans1 = tmp;
		}
		else if (tmp <= ans2)
			ans2 = tmp;
	}
	cout << ans1 + ans2 << '\n';
return 0;}
