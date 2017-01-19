#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	static vector<string> a[256];
	for (int i = 0; i < N; ++i){
		string s; cin >> s;
		a[s[0]].push_back(s);
	}
	for (char i = 'a'; i <= 'z'; ++i){
		if (a[i].empty())
			continue;
		sort(a[i].begin(), a[i].end());
		cout << a[i][0];
		for (int j = 1; j < a[i].size(); ++j)
			cout << ", " << a[i][j];
		cout << '\n';
	}
return 0;}

