#include <bits/stdc++.h>
using namespace std;

int N, L;
vector<string> A[26];

void dfs(string sofar, int pos){
	cout << sofar << ' ' << pos << '\n';
	if (ans.count(sofar))
		return;
	if (pos == N){
		ans.insert(sofar);
		return;
	}
	for (char c : A[pos])
		dfs(sofar + c, pos+1);
	if (pos != 0)
		dfs(sofar, pos+1);
}

int main(){
	//ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> L;
	for (int i = 0; i < N; ++i){
		int M; cin >> M;
		A[i].push_back("");
		for (int j = 0; j < M; ++j){
			char a; cin >> a;
			A[i].push_back(a);
		}
	}
	dfs("", 0);
	for (string s : ans)
		if (s.size() <= L)
			cout << s << '\n';
return 0;}
