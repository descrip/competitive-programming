#include <utility>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

bool isPrincess(string s){
	for (int i = 0; i < s.length()-10; ++i)
		if (s.substr(i,10) == " Princess ")
			return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	cin.ignore();
	vector<int> v;
	bool inGroup = false;
	vector<int> g;
	for (int i = 0; i < n; ++i){
		string s;
		getline(cin,s);
		if (isPrincess(s)){
			if (inGroup)
				++g[g.size()-1];
			else{
				g.pb(1);
				inGroup = true;
			}
		}
		else
			inGroup = false;
	}
	vector<int> t (g.size());
	for (int i = 0; i < g.size(); ++i)
		cin >> t[i];
	vector<pair<pair<int,int>,int>> kn (g.size());
	for (int i = 0; i < g.size(); ++i)
		kn[i] = {{t[i],-g[i]},i};
	sort(kn.begin(),kn.end());
	vector<int> ans;
	int l = kn[kn.size()-1].first.first;
	for (int m = 1; m <= l; ++m){
		auto it = lower_bound(kn.begin(),kn.end(),make_pair(make_pair(m,-500),0));
		if (it == kn.end())
			break;
		ans.pb((*it).second);
		kn[it-kn.begin()].first.second = -501;
		kn[it-kn.begin()].first.first = m;
	}
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i]+1 << "\n";
	return 0;
}
