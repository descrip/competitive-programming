#include <bits/stdc++.h>
using namespace std;

int A[1700][1005], L, T, ans1 = 0xfffffff, ans2 = 0xfffffff;
bool B[1700][1005];
set<int> S[1005];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> L >> T;
	for (int i = 1; i <= 1000; ++i)
		for (int j = L; j < 1700; ++j)
			S[i].insert(j);
	for (int t = 0; t < T; ++t){
		char E; int R, C; cin >> E >> R >> C;
		if (R >= 1700)
			continue;
		else if (E == 'E'){
			B[R][C] = true;
			S[C].erase(R);
			for (int i = R; i < 1700; ++i)
				++A[i][C];
		}
		else if (E == 'L'){
			B[R][C] = false;
			S[C].insert(R);
			for (int i = R; i < 1700; ++i)
				--A[i][C];
		}
		else{
			if (B[R][C] || B[R][C+1])
				cout << "No\n";
			else{
				int tmp = 0;
				for (int i = 1; i <= 1000; ++i){
					if (R - abs(C-i) >= 1)
						tmp += A[R - abs(C-i)][i];
					if (R - abs(C+1-i) >= 1)
						tmp += A[R - abs(C+1-i)][i];
				}
				cout << tmp << '\n';
			}
		}
	}
	/*
	for (int x = 1; x <= 1000; ++x){
		int tmp = 0, y = *S[x].begin();
		for (int i = 1; i <= 1000; ++i)
			if (y - abs(x-i) >= 1)
				tmp += A[y - abs(x-i)][i];
		if (tmp <= ans1){
			ans2 = ans1;
			ans1 = tmp;
		}
		else if (tmp < ans2)
			ans2 = tmp;
	}
	*/
	cout << ans1 + ans2 << '\n';
return 0;}

