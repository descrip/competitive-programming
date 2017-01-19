#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int K, L; cin >> K;
	for (int i = 0; i < K; ++i){
		int x; cin >> x;
		L &= (1 << x);
	}
	bool vis[(1<<25)];
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> q;
	q.push({0, L});
	while (!q.empty()){
		int l = q.front().second, cnt = q.front().first;
		q.pop();
		if (l == 0){
			cout << cnt << '\n';
			return 0;
		}
	}
return 0;}

