#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	static int a[3]; int l;
	for (int i = 0; i < 3; ++i)
		cin >> a[i];
	cin >> l;

	static bool prime[300001];
	fill(prime,prime+300001,true);
	prime[0] = prime[1] = false;
	vector<int> pri;
	for (int i = 2; i*i <= 300000; ++i)
		if (prime[i])
			for (int j = 2; i*j <= 300000; ++j)
				prime[i*j] = false;
	for (int i = 2; i <= 300000; ++i)
		if (prime[i])
			pri.push_back(i);

	cout << pri.size() << '\n';
	
return 0;}
