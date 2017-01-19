#include <bits/stdc++.h>
using namespace std;

int r, s, u, v, t, q;
int routes[1001][101];
set<pair<int,int>> times[101];

int main(){
	//cin.sync_with_stdio(0); cin.tie(0);
	cin >> s >> r >> u >> v >> t;
	for (int i = 0; i < r; ++i){
		int sr; cin >> sr;
		q += sr;
		int last; cin >> last;
		for (int j = 1; j < sr; ++j){
			int curr; cin >> curr;
			routes[i][last] = curr;
			last = curr;
		}
	}
	for (int i = 0; i < q; ++i){
		int a, b, c; cin >> a >> b >> c;
		for (int i = 0; i < c; ++i){
			int x; cin >> x;
			times[b-1].insert({x,a-1});
		}
	}
	priority_queue<pair<int,int>> q;
	q.push({t,u-1});
	set<int> prev;
	while (!q.empty()){
		int pos = q.top().second, time = q.top().first; q.pop();
		//cout << pos << ' ' << time << '\n';
		if (pos == v-1){
			cout << time - t << '\n';
			return 0;
		}
		else{
			prev.clear();
			auto it = times[pos].lower_bound({time,-1});
			while (it != times[pos].end()){
				if (prev.count(it->second) == 0){
					prev.insert(it->second);
					cout << it->first << ' ' << it->second << '\n';
					q.push({it->first,routes[it->second][pos]});
				}
				++it;
			}
		}
	}
	cout << "stay home\n";
return 0;}
