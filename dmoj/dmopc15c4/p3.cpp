#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int G; cin >> G;
	static int A[8];
	for (int g = 0; g < G; ++g){
		int N; cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> A[i];
		int T, H; cin >> H >> T;
		int sum = 0;
		for (int i = 0; i < N; ++i)
			sum += A[i];
		bool ok = false;
		for (int i = 1; i < (1<<N); ++i){
			int cnt = 0;
			for (int j = 0; j < N; ++j)
				if (i & (1<<j))
					cnt += A[j];
			if (cnt >= T && sum-cnt >= H){
				cout << "LETHAL\n";
				ok = true;
				break;
			}
		}
		if (!ok)
			cout << "NOT LETHAL\n";
	}
return 0;}

