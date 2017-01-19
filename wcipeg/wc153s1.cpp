#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M; cin >> N >> M;
	//cout << N << ' ' << M << '\n';
	vector<int> D (N);
	for (int i = 0; i < N; ++i)
		cin >> D[i];
	vector<int> rQ (M), Q;
	for (int i = 0; i < M; ++i)
		cin >> rQ[i];
	Q = rQ;
	map<int, int> qQ;
	sort(Q.begin(), Q.end(), greater<int>());
	long long tot = 0;
	for (int i = 0; i < N; ++i){
		tot += D[i];
		//cout << tot << '\n';
		while (!Q.empty() && *Q.rbegin() + tot < 0){
			qQ[*Q.rbegin()] = i;
			Q.pop_back();
			//cout << Q.size() << '\n';
		}
	}
	for (int i = 0; i < Q.size(); ++i)
		qQ[Q[i]] = N;
	for (int i : rQ)
		cout << qQ[i] << '\n';
return 0;}

