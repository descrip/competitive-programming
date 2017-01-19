#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	static int a[3][3];
	for (int i = 0; i < N; ++i){
		int M; cin >> M;
		for (int j = 0; j < M; ++j){
			cin >> a[i][j];
			for (int k = 0; k < i; ++k)
				for (int l = 0; l < 3; ++l)
					if (a[k][l] == a[i][j]){
						cout << "YES\n"; return 0;
					}
		}
	}
	cout << "NO\n";
return 0;}
