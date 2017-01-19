#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int N, K; cin >> N >> K;
	vector<int> V (N);
	for (int i = 0; i < N; ++i) cin >> V[i];
	for (int i = 0; i < min(N,K); ++i){
		auto it = max_element(V.begin()+i,V.end());
		if (it == V.begin()+i){
			++K; continue;
		}
		iter_swap(it,V.begin()+i);
	}
	for (int i = 0; i < V.size(); ++i)
		cout << V[i] << " \n"[i==V.size()-1];
return 0;}
