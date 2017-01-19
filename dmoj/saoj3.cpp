#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	string s;
	map<char,int> m;
	set<char> prev;
	vector<char> v;
	while (cin >> s){
		for (char c : s){
			if (65 <= c && c <= 65+26){
				m[c];
				++m[c];
				if (prev.count(c) == 0){
					prev.insert(c);
					v.push_back(c);
				}
			}
			else if (97 <= c && c <= 97+26){
				m[c-32];
				++m[c-32];
				if (prev.count((char)(c-32)) == 0){
					prev.insert((char)(c-32));
					v.push_back((char)(c-32));
				}
			}
		}
	}
	for (int i = 0; i < v.size(); ++i)
		cout << m[v[i]] << ' ';
	cout << '\n';
return 0;}
