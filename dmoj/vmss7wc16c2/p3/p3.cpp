#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	vector<int> L (1000001, 0xfffffff);
	for (int i = 0; i < N; ++i){
		int x; cin >> x;
		L[x] = i;
	}
	int M; cin >> M;
	set<int> S;
	for (int i = 0; i < M; ++i){
		int x; cin >> x;
		if (L[x] == 0xfffffff)
			continue;
		S.insert(L[x]);
		auto it = S.find(L[x]);
		++it;
		if (it != S.end())
			S.erase(it);
	}
	cout << S.size() << '\n';
return 0;}

