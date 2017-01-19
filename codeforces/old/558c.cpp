#include <bits/stdc++.h>
using namespace std;

int n, lim = 0;
vector<int> a;
vector<set<int,greater<int>>> b;

int decf(int a, int h){
	if (a < h)
		return -0x7fffffff;
	else if (a == h)
		return 0;
	else
		return 1 + decf(a/2,h);
}

int dec2(int a, int i){
	b[i].insert(a);
	if (a == 1)
		return 0;
	else
		return 1 + dec2(a/2,i);
}

int inc2(int a, int i){
	b[i].insert(a);
	if (a > 400000)
		return 0;
	else
		return 1 + dec2(a*2,i);
}

int incf(int a, int h){
	if (a > h)
		return -0x7fffffff;
	else if (a == h)
		return 0;
	else
		return 1 + incf(a*2,h);
}

int gao(int h){
	int ans = 0;
	for (int i = 0; i < n; ++i){
		if (a[i] == h) continue;
		else if (a[i] < h){
			int tmp = incf(a[i],h);
			if (tmp < 0)
				return 0x7fffffff;
			else
				ans += tmp;
		}
		else if (a[i] > h){
			int tmp = decf(a[i],h);
			if (tmp < 0)
				return 0x7fffffff;
			else
				ans += tmp;
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	a.assign(n,0);
	b.assign(n,set<int,greater<int>>());
	int ans = 0x7fffffff;
	if (n == 1){
		cout << 0 << '\n';
		return 0;
	}
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		lim = max(lim,a[i]);
	}
	for (int i = 0; i < n; ++i)
		ans = min(ans,gao(a[i]));
	for (int i = 0; i < n; ++i){
		inc2(a[i],i);
		dec2(a[i],i);
	}
	if (ans != 0x7fffffff){
		cout << ans << '\n';
		return 0;
	}
	for (int i : b[0]){
		for (int j = 1; j < n; ++j)
			if (b[j].count(i) == 0)
				break;
			else if (j == n-1)
				ans = min(ans,gao(i));
	}
	cout << ans << '\n';
return 0;}
