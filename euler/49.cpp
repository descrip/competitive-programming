#include <bits/stdc++.h>
using namespace std;

bool isPerm(int a, int b, int c){
	static int ten1[10], ten2[10], ten3[10];
	fill_n(ten1, 10, 0);
	fill_n(ten2, 10, 0);
	fill_n(ten3, 10, 0);
	while (a > 0){
		++ten1[a % 10];
		a /= 10;
	}
	while (b > 0){
		++ten2[b % 10];
		b /= 10;
	}
	while (c > 0){
		++ten3[c % 10];
		c /= 10;
	}
	for (int i = 0; i <= 9; ++i)
		if (!(ten1[i] == ten2[i] && ten2[i] == ten3[i]))
			return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	static bool prime[10000];
	fill_n(prime, 10000, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i * i < 10000; ++i)
		if (prime[i])
			for (int j = 2; i * j < 10000; ++j)
				prime[i*j] = false;
	for (int i = 1000; i < 10000; ++i)
		if (prime[i] && i != 1487)
			for (int j = i+1; j < 10000; ++j)
				if (prime[j])
					if ((i + j) % 2 == 0 && prime[(i + j) / 2] && isPerm(i, j, (i + j) / 2)){
						cout << i << (i + j) / 2 << j << '\n';
						return 0;
					}
return 0;}

