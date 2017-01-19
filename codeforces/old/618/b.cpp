#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	static int A[50][50];
	for (int y = 0; y < N; ++y)
		for (int x = 0; x < N; ++x)
			cin >> A[y][x];
	static int P[50];
	for (int z = 1; z <= N; ++z){
		//cout << z << '\n';
		/*
		for (int y = 0; y < N; ++y){
			for (int x = 0; x < N; ++x)
				cout << A[y][x] << ' ';
			cout << '\n';
		}
		*/
		bool ok = false;
		for (int y = 0; y <= N; ++y){
			if (P[y] != 0)
				continue;
			for (int x = 0; x <= N; ++x)
				if (x == N){
					P[y] = z;
					for (int k = 0; k < N; ++k){
						A[y][k] = 0;
						A[k][y] = 0;
					}
					ok = true;
				}
				else if (A[y][x] <= 0)
					continue;
				else if (A[y][x] != z)
					break;
			if (ok)
				break;
		}
	}
	for (int i = 0; i < N; ++i)
		cout << P[i] << ' ';
	cout << '\n';
return 0;}

