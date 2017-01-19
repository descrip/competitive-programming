#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
ull pow3[50];
bool wow = false;

ull low3(ull A){
	ull R = 0ULL;
	for (int i = 39; i >= 0; --i)
		if (pow3[i] <= A){
			A -= pow3[i];
			R = R | (1ULL << i);
			//cout << i << ' ' << R << '\n';
		}
	if (A == 0)
		wow = true;
	return R;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int Q; cin >> Q;
	pow3[0] = 1ULL;
	for (int i = 1; i <= 39; ++i)
		pow3[i] = pow3[i-1] * 3ULL;
	for (int q = 0; q < Q; ++q){
		wow = false;
		ull L, R; cin >> L >> R;
		ull r = low3(R), l = low3(L);
		//cout << l << ' ' << r << ' ' << wow << '\n';
		cout << r - l + wow << '\n';
	}
return 0;}

