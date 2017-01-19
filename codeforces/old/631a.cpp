#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	static int A[2];
	for (int k = 0; k < 2; ++k)
		for (int i = 0; i < N; ++i){
			int x; cin >> x;
			A[k] |= x;
		}
	cout << A[0] + A[1] << '\n';
return 0;}

