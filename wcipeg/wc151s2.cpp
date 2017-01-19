#include <bits/stdc++.h>
using namespace std;

/*
 * WILDCATS@#*
 * 01234567890
 */

int B[11];

bool func(int n){
	static int A[11];
	for (int i = 0; i < 11; ++i)
		A[i] = B[i];
	for (int i = 0; i < 8; ++i){
		int r = n, t = min(A[i], r);
		A[i] -= t;
		r -= t;
		//cout << n << ' ' << i << ' ' << r << '\n';
		if (r > 0){
			if (i == 1 || i == 5){
				t = min(A[8], r);
				A[8] -= t;
			}
			else{
				t = min(A[9], r);
				A[9] -= t;
			}
			r -= t;
		}
		if (r > 0){
			t = min(A[10], r);
			A[10] -= t;
			r -= t;
		}
		//cout << n << ' ' << i << ' ' << r << '\n';
		if (r > 0)
			return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 11; ++i)
		cin >> B[i];
	//cout << func(1) << ' ' << func(2) << ' ' << func(100) << '\n';
	int lo = 0, hi = 1e9;
	while (lo+1 < hi){
		//cout << lo << ' ' << hi << '\n';
		int mid = lo + (hi - lo) / 2;
		if (func(mid))
			lo = mid;
		else
			hi = mid;
	}
	cout << lo << '\n';
return 0;}

