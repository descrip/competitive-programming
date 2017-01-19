#include <bits/stdc++.h>
using namespace std;

int s;
vector<pair<int,int>> stops;
vector<int> on (4000000);

int go(int x){
	int ret = 1;
	on[0] = 0;
	for (auto p : stops){
		for (int i = 0; i < ret; ++i){
			on[i] -= (int)(floor((double) on[i] * p.second / 100));
			if (p.first > x - on[i]){
				p.first -= (x - on[i]);
				on[i] = x;
				if (i == ret-1) on[ret++] = 0;
			}
			else{
				on[i] += p.first;
				p.first = 0;
			}
		}
		/*
		for (int i = 0; i < ret; ++i)
			cout << on[i] << " \n"[i == ret-1];
			*/
	}
	return ret;
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> s;
	stops.assign(s,pair<int,int>());
	for (int i = 0; i < s; ++i)
		cin >> stops[i].first >> stops[i].second;
	cout << go(132) - go(251) << '\n';
return 0;}
