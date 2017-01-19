#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	int i = 0;
	vector<int> v;
	for (; i < s.size()-1; ++i)
		if (s[i] == 'A' && s[i+1] == 'B')
			v.push_back(i);
	for (int j = 0; j < s.size()-1; ++j)
		if (s[j] == 'B' && s[j+1] == 'A'){
			for (int k : v)
				if (abs(k-j) > 1){
					cout << "YES\n"; return 0;
				}
			if (j == s.size()-2){
				cout << "NO\n"; return 0;
			}
		}
		else if (j == s.size()-2){
			cout << "NO\n"; return 0;
		}
	cout << "NO\n";
return 0;}
