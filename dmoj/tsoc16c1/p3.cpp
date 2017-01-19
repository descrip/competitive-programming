#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	static int A[4];
	for (int y = 0; y < 2*N; ++y)
		for (int x = 0; x < 2*N; ++x){
			char c; cin >> c;
			if (c == 'g'){
				if (x >= N){
					if (y < N)
						++A[0];
					else
						++A[3];
				}
				else{
					if (y < N)
						++A[1];
					else
						++A[2];
				}
			}
		}
	int ans = 0;
	for (int i = 0; i < 4; ++i)
		ans = max(ans, A[i]);
	for (int i = 0; i < 4; ++i)
		if (A[i] == ans){
			cout << i+1 << '\n';
			return 0;
		}
return 0;}

