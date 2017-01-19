#include <algorithm>
#include <set>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

int N;
set<int> S, T;
vector<pair<int,int>> E;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	ifstream fin ("stampede.in");
	fin >> N;
	for (int i = 0; i < N; ++i){
		int x, y, r; fin >> x >> y >> r;
		E.push_back({-x*r,-y});
		E.push_back({-x*r-r,y});
	}
	sort(E.begin(),E.end());
	for (int i = 0; i < E.size(); ){
		int j;
		for (j = i; j < E.size() && E[i].first == E[j].first; ++j){
			int y = E[j].second;
			if (y < 0) S.erase(-y);
			else S.insert(y);
		}
		if(!S.empty()) T.insert(*S.begin());
		i = j;
	}
	ofstream fout ("stampede.out");
	fout << T.size() << '\n';
	fout.close();
	fin.close();
return 0;}
