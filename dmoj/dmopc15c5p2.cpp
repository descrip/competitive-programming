#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	vector<string> V = {"elpsycongroo", "tuturu", "superhacker", "myfork"}, W = {"Okabe", "Mayuri", "Daru", "Kurisu"};
	static bool A[4];
	for (int i = 0; i < N; ++i){
		string s; cin >> s;
		int cnt = 0;
		for (int i = 0; i < 4; ++i){
			int pos = 0;
			for (int j = 0; j < s.size(); ++j)
				if (s[j] == V[i][pos])
					++pos;
			if (pos == V[i].size()){
				A[i] = true;
				++cnt;
			}
			else
				A[i] = false;
		/*
			if (s.find(V[i]) != string::npos){
				A[i] = true;
				++cnt;
			}
			else
				A[i] = false;
		*/
		}
		if (cnt == 0)
			cout << "SERN spy!\n";
		for (int i = 0; i < 4; ++i)
			if (A[i]){
				cout << W[i] << (cnt > 1 ? " or " : "\n");
				--cnt;
			}
	}
return 0;}

