#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int N;
vector<pair<int,int>> V;
set<int> best;

void gao(){
	best.clear();
	vector<pair<int,int>> events;
	for (int i = 1; i < V.size(); ++i){
		events.push_back({V[i].first,-i});
		events.push_back({V[i].second,i});
	}
	sort(events.begin(),events.end());
	set<int> act;
	for (auto p : events){
		if (p.second > 0)
			act.erase(p.second);
		else{
			act.insert(-p.second);
			if (act.size() > best.size()) best = act;
		}
	}
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	for (int ts = 1; ts <= T; ++ts){
		cin >> N;
		V.assign(N+1,pair<int,int>());
		for (int i = 1; i <= N; ++i)
			cin >> V[i].first >> V[i].second;
		gao();
		int ans = best.size();
		for (auto it = best.rbegin(); it != best.rend(); ++it)
			V.erase(V.begin()+*it);
		gao();
		cout << "Case " << ts << ": " << ans + best.size() << '\n';
	}
return 0;}
