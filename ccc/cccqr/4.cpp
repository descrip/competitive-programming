#include <bits/stdc++.h>
using namespace std;

int N, Q;
vector<int> adj[100005];
map<pair<int, int>, int> M;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i){
		int k; cin >> k;
		//cout << k << '\n';
		for (int j = 0; j < k; ++j){
			int x; cin >> x;
			adj[i].push_back(x);
		}
	}
	//cout << adj[1][0] << '\n';
	cin >> Q;
	set<pair<pair<int, int>, int>> hist;
	while (Q--){
		int start; cin >> start;
		int cnt = 0;
		for (int i = 0; i <= adj[start].size(); ++i){
			hist.clear();
			int pos = start, last = adj[start][i];
			if (M.count(make_pair(pos, last)) != 0){
				//cout << pos << ' ' << last << ' ' << M[make_pair(pos, last)] << '\n';
				cnt = max(cnt, M[make_pair(pos, last)]);
				continue;
			}
			bool ok = false;
			int curr = 0;
			while (!(pos == start && ok)){
				//cout << "P " << pos << ' ' << last << '\n';
				auto it = hist.lower_bound(make_pair(make_pair(pos, -1), -1));
				if (it != hist.end() && it->first.first == pos)
					M[make_pair(it->first.first, it->first.second)] = curr - it->second;
				hist.insert({{pos, last}, curr});
				for (int i = 0; i < adj[pos].size(); ++i)
					if (adj[pos][i] == last){
						last = pos;
						pos = adj[last][(i+1)%adj[last].size()];
						break;
					}
				ok = true;
				++curr;
			}
			/*
			cout << last << '\n';
			for (int i : adj[pos])
				cout << i << ' ';
			cout << '\n';
			*/
			cnt = max(cnt, curr);
		}
		cout << cnt << '\n';
	}
return 0;}

