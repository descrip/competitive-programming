#include <bits/stdc++.h>
using namespace std;

const long long MAXN = 2147483647;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	static bool isComp[MAXN+1];
	isComp[0] = isComp[1] = true;
	vector<int> primes;
	for (int i = 2; i <= sqrt(MAXN); ++i)
		if (!isComp[i]){
			primes.push_back(i);
			for (int j = 2; i*j <= sqrt(MAXN); ++j)
				isComp[i*j] = true;
		}
	int N; cin >> N;
	for (int n = 0; n < N; ++n){
		int a, b; cin >> a >> b;
		for (int i = 0; primes[i]*primes[i] <= b; ++i)
			for (int j = max((int)(a/primes[i]), 2); j <= b/primes[i]; ++j)
				isComp[primes[i]*j] = true;
		for (int i = a; i <= b; ++i)
			if (!isComp[i])
				cout << i << '\n';
	}
return 0;}

