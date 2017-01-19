#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	static char A[200][200];
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> A[i][j];
	long long ans = 0;
	for (int y = 0; y < N; ++y){
		long long curr = 0;
		for (int x = 0; x < N; ++x)
			if (A[y][x] == 'C')
				++curr;
		ans += curr * (curr-1) / 2;
	}
	for (int y = 0; y < N; ++y){
		long long curr = 0;
		for (int x = 0; x < N; ++x)
			if (A[x][y] == 'C')
				++curr;
		ans += curr * (curr-1) / 2;
	}
	cout << ans << '\n';
return 0;}

