#include <bits/stdc++.h>
using namespace std;

struct node{
	long long one = 0, two = 0, three = 0;
};

bool operator<(const node &a, const node &b){
	return a.one < b.one;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k; cin >> n >> k;
	vector<int> a (n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	long long ans = 0;
	set<pair<int,node>> look;
	for (int i = 0; i < n; ++i){
		auto it = look.lower_bound(make_pair(a[i],node()));
		node tmp = node();
		if (it != look.end() && it->first == a[i])
			tmp = it->second;
		tmp.one++;
		if (a[i] % k == 0){
			auto it2 = look.lower_bound(make_pair(a[i]/k,node()));
			if (it2 != look.end() && it2->first == a[i]/k){
				tmp.two += it2->second.one;
				tmp.three += it2->second.two;
				ans += it2->second.two;
			}
		}
		if (it != look.end() && it->first == a[i])
			look.erase(it);
		look.insert(make_pair(a[i],tmp));
	}
	cout << ans << '\n';
return 0;}
