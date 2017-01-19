#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, Q; cin >> N >> Q;
	vector<int> cows (N);
	static vector<int> psum[3];
	for (int i = 0; i < N; ++i)
		cin >> cows[i];
	for (int i = 0; i < 3; ++i)
		psum[i].push_back(0);
	++psum[cows[0]-1][0];
	for (int i = 1; i < N; ++i){
		for (int j = 0; j < 3; ++j)
			psum[j].push_back(psum[j].back());
		++psum[cows[i]-1][i];
		/*
		for (int j = 0; j < 3; ++j)
			cout << psum[j][i] << ' ';
		cout << '\n';
		*/
	}
	for (int i = 0; i < Q; ++i){
		int a, b; cin >> a >> b;
		for (int j = 0; j < 3; ++j)
			if (a == 1)
				cout << psum[j][b-1] << " \n"[j==2];
			else
				cout << psum[j][b-1] - psum[j][a-2] << " \n"[j==2];
	}
return 0;}

