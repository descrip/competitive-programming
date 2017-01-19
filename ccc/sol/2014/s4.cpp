#include <map>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

#define pb push_back
typedef long long ll;
typedef unsigned long long ull;

int main(){
	int n;
	ll t;
	scanf("%d %lld",&n,&t);
	vector<vector<ll>> rects (n+1, vector<ll> (5));
	vector<ll> itox, itoy;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < 5; ++j)
			scanf("%lld",&rects[i][j]);
		itox.pb(rects[i][0]);
		itox.pb(rects[i][2]);
		itoy.pb(rects[i][1]);
		itoy.pb(rects[i][3]);
	}

	sort(itox.begin(),itox.end());
	sort(itoy.begin(),itoy.end());
	unique(itox.begin(),itox.end());
	unique(itoy.begin(),itoy.end());
	
	map<ll,int> xtoi, ytoi;
	for (int i = 0; i < itox.size(); ++i)
		xtoi[itox[i]] = i;
	for (int i = 0; i < itoy.size(); ++i)
		ytoi[itoy[i]] = i;
	
	vector<vector<int>> da (itoy.size(),vector<int>(itox.size()));
	for (int i = 0; i < rects.size(); ++i){
		for (int j = ytoi[rects[i][1]]; j < ytoi[rects[i][3]]; ++j){
			da[j][xtoi[rects[i][0]]] += rects[i][4];
			da[j][xtoi[rects[i][2]]] -= rects[i][4];
		}
	}
	
	ll ans = 0;
	for (int i = 0; i < itoy.size() - 1; ++i){
		for (int j = 0; j < itox.size() - 1; ++j){
			da[i][j+1] += da[i][j];
			if (da[i][j] >= t)
				ans += (itox[j+1] - itox[j]) * (itoy[i+1] - itoy[i]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
