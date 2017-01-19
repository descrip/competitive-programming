#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M; cin >> N >> M;
	vector<string> A (N);
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	int ans1 = 0, ans2 = 1;
	for (int i = 0; i < M; ++i){
		int minCost = 0xfffffff, minCnt = 0;
		for (char z = 'A'; z <= 'Z'; ++z){
			int currCost = 0;
			for (int j = 0; j < N; ++j)
				if (A[j][i] != '?' && A[j][i] != z)
					++currCost;
			if (currCost < minCost){
				minCost = currCost;
				minCnt = 1;
			}
			else if (currCost == minCost)
				++minCnt;
		}
		ans1 += minCost; ans2 = (ans2 * minCnt) % 1000;
	}
	cout << ans1 << ' ' << ans2 << '\n';
return 0;}

