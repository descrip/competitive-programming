#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	vector<int> V (N+5);
	for (int i = 1; i <= N; ++i)
		cin >> V[i];
	static bool take[5];
	for (int i = 1; i <= N; ++i){
		if (V[i] == 0){
			fill_n(take, 5, false);
			take[V[i-1]] = take[V[i+1]] = true;
			for (int j = 1; j <= 4; ++j)
				if (!take[j]){
					V[i] = j;
					break;
				}
		}
		cout << V[i];
	}
	cout << '\n';
return 0;}

