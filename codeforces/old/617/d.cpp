#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<pair<int,int>> V (3);
	for (int i = 0; i < 3; ++i)
		cin >> V[i].first >> V[i].second;
	if ((V[0].first == V[1].first && V[1].first == V[2].first) || 
		(V[0].second == V[1].second && V[1].second == V[2].second)){
		cout << "1\n";
		return 0;
	}
	for (int i = 0; i < 3; ++i)
		for (int j = i+1; j < 3; ++j)
			if ((V[i].first == V[j].first && !(min(V[i].second, V[j].second) < V[3-i-j].second && V[3-i-j].second < max(V[j].second, V[i].second))) || 
			(V[i].second == V[j].second && !(min(V[i].first, V[j].first) < V[3-i-j].first && V[3-i-j].first < max(V[j].first, V[i].first)))){
				cout << "2\n";
				return 0;
			}
	cout << "3\n";
return 0;}

