#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	static set<int> todo[8];
	todo[7].insert(1);
	todo[4].insert(1);
	todo[1].insert(2);
	todo[4].insert(3);
	todo[5].insert(3);
	while (true){
		int x, y; cin >> x >> y;
		if (x == 0 && y == 0)
			break;
		todo[y].insert(x);
	}
	static bool done[8];
	vector<int> ans;
	while (ans.size() < 7){
		bool ok = false;
		for (int i = 1; i <= 7; ++i)
			if (!done[i] && todo[i].empty()){
				done[i] = true;
				ans.push_back(i);
				for (int j = 1; j <= 7; ++j)
					todo[j].erase(i);
				ok = true;
				break;
			}
		if (!ok){
			cout << "Cannot complete these tasks. Going to bed.\n";
			return 0;
		}
	}
	for (int i : ans)
		cout << i << ' ';
	cout << '\n';
return 0;}

