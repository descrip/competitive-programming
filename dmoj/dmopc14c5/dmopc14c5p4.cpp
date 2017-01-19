#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main(){
	int n, m; cin >> n >> m;
	vector<int> bad, good;
	for (int i = 0; i < n; ++i){
		int s, p; cin >> s >> p;
		if (p == 1) bad.push_back(s);
		else good.push_back(s);
	}
	sort(bad.begin(),bad.end());
	sort(good.begin(),good.end());
	vector<int> badps (bad.size()), goodps (good.size());
	if (badps.size() > 0) badps[0] = bad[0];
	if (goodps.size() > 0) goodps[0] = good[0];
	for (int i = 1; i < badps.size(); ++i) badps[i] = badps[i-1] + bad[i];
	for (int i = 1; i < goodps.size(); ++i) goodps[i] = goodps[i-1] + good[i];
	int best = 0;
	int g;
	for (g = 0; g < goodps.size(); ++g)
		if (goodps[g] > m)
			break;
	--g;
	if (g != -1)
		best = max(best,2*(g+1));
	int b = 0;
	for (; g >= -1; --g){
		for (; b < badps.size(); ++b)
			if (badps[b] > m - (g == -1 ? 0 : goodps[g])) break;
		--b;
		if (b == -1) break;
		best = max(best,2*(g+1)+b+1);
	}
	cout << best << '\n';
return 0;}
