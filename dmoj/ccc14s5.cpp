#include <bits/stdc++.h>
using namespace std;

long long dist(const pair<int, int> &a, const pair<int, int> &b){
	long long dx = a.first - b.first, dy = a.second - b.second;
	return dx*dx + dy*dy;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	vector<pair<int, int>> V (N+1);
	vector<pair<long long, pair<int, int>>> E;
	for (int i = 1; i <= N; ++i)
		cin >> V[i].first >> V[i].second;
	for (int i = 0; i <= N; ++i)
		for (int j = i+1; j <= N; ++j)
			E.push_back({dist(V[i], V[j]), {i, j}});
	sort(E.begin(), E.end());
	static long long D[2005];
	static int C[2005], pC[2005];
	for (auto p : E){
		int d = p.first, a = p.second.first, b = p.second.second;
		if (d != D[a]){
			D[a] = d;
			pC[a] = C[a];
		}
		if (d != D[b]){
			D[b] = d;
			pC[b] = C[b];
		}
		C[a] = max(C[a], pC[b]+1);
		if (a != 0)
			C[b] = max(C[b], pC[a]+1);
	}
	/*
	for (int i = 0; i < N; ++i)
		cout << C[i] << " \n"[i==N-1];
	*/
	cout << C[0] << '\n';
return 0;}

