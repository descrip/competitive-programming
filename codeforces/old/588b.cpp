#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long n; cin >> n;
	vector<long long> div;
	for (long long i = 2; i*i <= n; ++i)
		if (n % (i*i) == 0)
			div.push_back(i*i);
	long long ans = 1;
	for (long long i = n; i >= sqrt(n); --i){
		if (n % i == 0){
			bool ok = true;
			for (int j = 0; j < div.size(); ++j)
				if (div[j] <= i && i % j == 0)
					ok = false;
		}
	}
return 0;}
