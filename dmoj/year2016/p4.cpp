#include <bits/stdc++.h>
using namespace std;

int N, cnt = 1;
vector<int> adj[50000], perm;

void recur(int pos, vector<int> &cont){
	cont.push_back(cnt++);
	vector<vector<int>> ret (adj[pos].size(), vector<int>());
	for (int i = adj[pos].size()-1; i >= 0; --i)
		recur(adj[pos][i], ret[i]);
	for (int i = 0; i < ret.size(); ++i)
		for (int j = 0; j < ret[i].size(); ++j)
			cont.push_back(ret[i][j]);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i){
		int K; cin >> K;
		for (int j = 0; j < K; ++j){
			int a; cin >> a;
			adj[i].push_back(a-1);
		}
	}
	recur(0, perm);
	for (int i = 0; i < N; ++i)
		cout << perm[i] << " \n"[i==N-1];
return 0;}

