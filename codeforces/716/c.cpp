#include <bits/stdc++.h>
using namespace std;

int N, K = 1;
long long A = 2;

long long fast_pow(int a,int n)
{
    long long result = 1;
    long long power = n;
    long long value = a;
    while(power>0)
    {
        if(power&1)
			result = result*value;
        value = value*value;
        value = value;
        power >>= 1;
    }
    return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	cout << 2 << '\n';
	++K;
	A = 2;
	while (K <= N) {
		int U = ceil(log((long double)A) / log((long double)K));
		if (U % 2 == 1) ++U;
		U /= 2;
		long long tmp2 = fast_pow(K+1, U),
			 tmp1 = fast_pow(K, U);
		//cout << tmp1 << ' ' << tmp2 << '\n';
		cout << tmp1*tmp1*tmp2/K*tmp2 - A/K << '\n';
		A = tmp1*tmp2;
		++K;
	}
	return 0;
}

