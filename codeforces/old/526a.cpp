#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	map<int,int> m;
	vector<int> prev = {0};
	for (int i = 1; i < s.size(); ++i){
		if (s[i] == '*'){
			for (int j : prev){
				m[i-j];
				++m[i-j];
			}
			prev.push_back(i);
		}
	}
	for (int i = 1; i < s.size(); ++i){
		if (m[i] >= 4){
			cout << "yes\n";
			return 0;
		}
	}
	cout << "no\n";
return 0;}
