#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	vector<pair<int,int>> V (N);
	for (int i = 0; i < N; ++i)
		cin >> V[i].first >> V[i].second;
	sort(V.begin(), V.end());
	for (int i = 1; i < N; ++i){
		if (V[i].second < V[i-1].second){
			cout << "Happy Alex\n";
			return 0;
		}
	}
	cout << "Poor Alex\n";
return 0;}
