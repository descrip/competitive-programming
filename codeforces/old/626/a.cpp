#include <bits/stdc++.h>
using namespace std;

pair<int, int> func(const string &s){
	pair<int, int> a = {0, 0};
	for (char c : s){
		if (c == 'U')
			--a.second;
		else if (c == 'D')
			++a.second;
		else if (c == 'R')
			++a.first;
		else
			--a.first;
	}
	return a;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	string s; cin >> s;
	//pair<int, int> e = func(s);
	int ans = 0;
	for (int i = 0; i < N; ++i)
		for (int j = i+1; j < N; ++j)
			if (make_pair(0, 0) == func(s.substr(i, j-i+1)))
				++ans;
	cout << ans << '\n';
return 0;}

