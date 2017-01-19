#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e9;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	static bool isComp[(int)sqrt(MAXN)+2];
	isComp[0] = isComp[1] = true;
	vector<int> primes;
	for (int i = 2; i <= sqrt(MAXN); ++i)
		if (!isComp[i]){
			primes.push_back(i);
			for (int j = 2; i*j <= sqrt(MAXN); ++j)
				isComp[i*j] = true;
		}
	int N; cin >> N;
	for (int i = 0; i < N; ++i){
		int a, b; cin >> a >> b;
		for (int j = a; j <= b; ++j)
			for (int k = 0; k < primes.size(); ++k)
				if (primes[k] < j && j % primes[k] == 0)
					break;
				else if (k == primes.size()-1 && j != 1)
					cout << j << '\n';
		if (i != N-1)
			cout << '\n';
	}
return 0;}

