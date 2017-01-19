#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	vector<pair<int, int>> V (N+1);
	for (int i = 1; i <= N; ++i){
		cin >> V[i].first >> V[i].second;
		V[i].first += 1000;
		V[i].second += 1000;
	}
	V[0] = {1000,1000};
	static int dpX[2][2002], dpY[2][2002];
	fill_n(dpX[0], 2*2002, 0xfffffff);
	fill_n(dpY[0], 2*2002, 0xfffffff);
	dpX[0][1000] = dpY[0][1000] = 0;
	for (int i = 1; i <= N; ++i){
		for (int x = 0; x <= 2000; ++x)
			dpY[i%2][x] = 0xfffffff;
		for (int y = 0; y <= 2000; ++y)
			dpX[i%2][y] = 0xfffffff;
		for (int y = 0; y <= 2000; ++y){
			dpX[i%2][y] = min(dpX[i%2][y], dpX[(i-1)%2][y] + abs(V[i].first - V[i-1].first));
			dpY[i%2][V[i-1].first] = min(dpY[i%2][V[i-1].first], dpX[(i-1)%2][y] + abs(V[i].second - y));
			//dpX[i%2][2001] = min(dpX[i%2][2001], dpX[i%2][y]);
		}
		for (int x = 0; x <= 2000; ++x){
			dpY[i%2][x] = min(dpY[i%2][x], dpY[(i-1)%2][x] + abs(V[i].second - V[i-1].second));
			dpX[i%2][V[i-1].second] = min(dpX[i%2][V[i-1].second], dpY[(i-1)%2][x] + abs(V[i].first - x));
			//dpY[i%2][2001] = min(dpY[i%2][2001], dpY[i%2][x]);
		}
	}

	/*
	for (int i = 0; i < 2; ++i)
		cout << dpX[i][2001] << ' ' << dpY[i][2001] << '\n';
		*/

	//cout << dpX[2][1000] << ' ' << dpY[3][1007] << ' ' << dpY[4][1007] << '\n';

	int ans = 0xfffffff;
	for (int i = 0; i <= 2000; ++i)
		ans = min(ans, min(dpX[N%2][i], dpY[N%2][i]));
	cout << ans << '\n';
return 0;}

