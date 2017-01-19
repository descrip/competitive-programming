#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	string s, t; cin >> s >> t;
	int dist = 0;
	for (int i = 0; i < n; ++i)
		if (s[i] != t[i]) ++dist;
	set<pair<char,int>> prev;
	for (int i = 0; i < n; ++i){
		if (s[i] != t[i]){
			auto it = prev.lower_bound(make_pair(t[i],-1));
			if (it != prev.end() && it->first == t[i] && t[it->second] == s[i]){
				cout << dist-2 << '\n';
				cout << i+1 << ' ' << it->second+1 << '\n';
				return 0;
			}
			prev.insert(make_pair(s[i],i));
		}
	}
	for (int i = 0; i < n; ++i){
		if (s[i] != t[i]){
			auto it = prev.lower_bound(make_pair(t[i],-1));
			if (it != prev.end() && it->first == t[i]){
				cout << dist-1 << '\n';
				cout << it->second+1 << ' ' << i+1 << '\n';
				return 0;
			}
		}
	}
	cout << dist << '\n';
	cout << "-1 -1\n";
return 0;}
