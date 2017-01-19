#include <bits/stdc++.h>
using namespace std;

//8 and 9 pandigital numbers are multiples of 3
const int LIM = 7654322;

int main(){
	//ios_base::sync_with_stdio(0); cin.tie(0);
	static bool prime[LIM];
	fill_n(prime, LIM, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i * i < LIM; ++i)
		if (prime[i])
			for (int j = 2; i * j < LIM; ++j)
				prime[i * j] = false;
	static bool ten[10];
	for (int i = LIM-1; i >= 0; --i)
		if (prime[i]){
			int n = i;
			fill_n(ten, 10, false);
			while (n > 0){
				ten[n % 10] = true;
				n /= 10;
			}
			for (int j = 1; j <= (int)floor(log10(i)+1); ++j)
				if (!ten[j])
					break;
				else if (j == (int)floor(log10(i)+1)){
					cout << i << '\n';
					return 0;
				}
		}
return 0;}

