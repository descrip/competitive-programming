#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int H, M, N; cin >> H >> M >> N;
	--H;
	if (N > 60-M){
		N -= (60-M);
		M = 0;
		H = (H+1) % 24;
	}
	H = (H + N / 60) % 24;
	M = M + N % 60;
	if (M >= 60){
		M = 0;
		H = (H+1) % 24;
	}
	cout << (H+1)%24 << ' ' << M << '\n';
return 0;}

