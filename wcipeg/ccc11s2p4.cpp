#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	static pair<int, int> super[100005];
	set<pair<int, int>> ser;
	int tmp; cin >> tmp;
	ser.insert({-tmp, -1});
	for (int i = 2; i <= N; ++i){
		/*
		cout << i << '\n';
		for (auto j : ser)
			cout << '(' << j.first << ", " << j.second << ") ";
		cout << '\n';
		*/
		int R; cin >> R;
		auto it = ser.lower_bound(make_pair(-R, -i));
		if (it == ser.end()){
			cout << "NO\n";
			return 0;
		}
		int pos = -(it->second);
		if (super[pos].first == 0)
			super[pos].first = i;
		else{
			super[pos].second = i;
			ser.erase(it);
		}
		ser.insert({-R, -i});
	}
	cout << "YES\n";
return 0;}

