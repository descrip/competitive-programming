#include <bits/stdc++.h>
using namespace std;

struct visOrder{
	bool operator() (const pair<int, int> &a, const pair<int, int> &b){
		if (a.first == b.first){
			if (a.first % 2 == 1)
				return a.second < b.second;
			else 
				return a.second > b.second;
		}
		return a.first < b.first;
	}
};

int dist(const pair<int, int> &a, const pair<int, int> &b){
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	set<pair<int, int>, visOrder> S;
	S.insert({1, 1});
	int N; cin >> N;
	int ans = 0;
	for (int i = 0; i < N; ++i){
		pair<int, int> tmp;
		cin >> tmp.first >> tmp.second;
		S.insert(tmp);
		auto it = S.find(tmp);
		if (*it == *S.rbegin()){
			auto it2 = it;
			--it2;
			ans += dist(*it2, *it);
		}
		else if (it == S.begin()){
			auto it2 = it;
			++it2;
			ans += dist(*it2, *it);
		}
		else{
			auto it2 = it, it3 = it;
			--it2; ++it3;
			ans += -dist(*it2, *it3) + dist(*it2, *it) + dist(*it, *it3);
		}
		cout << ans << '\n';
	}
return 0;}

