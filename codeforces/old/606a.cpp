#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<int> v (3), w (3);
	for (int i = 0; i < 3; ++i)
		cin >> v[i];
	for (int i = 0; i < 3; ++i)
		cin >> w[i];
	while (true){
		for (int i = 0; i < 3; ++i)
			if (v[i] < w[i])
				break;
			else if (i == 2){
				cout << "Yes\n";
				return 0;
			}
		for (int i = 0; i < 3; ++i)
			if (v[i] >= w[i]+2){
				for (int j = 0; j < 3; ++j)
					if (v[j] < w[j]){
						v[j]++;
						v[i] -= 2;
						break;
					}
				break;
			}
			else if (i == 2){
				cout << "No\n";
				return 0;
			}
	}
return 0;}

