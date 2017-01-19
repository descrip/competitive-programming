#include <bits/stdc++.h>
using namespace std;

int n, k, tree[100000][26], win[100000], lose[100000], tick = 1;

void build(string s){
	int i = 0, v = 0;
	while (i < s.size()){
		if (tree[v][s[i]-'a'] == -1)
			v = tree[v][s[i++]-'a'] = tick++;
		else
			v = tree[v][s[i++]-'a'];
	}
}

void dfs(int u){
	bool has = false;
	for (int i = 0; i < 26; ++i)
		if (tree[u][i] != -1){
			has = true;
			dfs(tree[u][i]);
			win[u] |= !win[tree[u][i]];
			lose[u] |= !lose[tree[u][i]];
		}
	if (!has) lose[u] = true;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	fill_n(tree[0], 26*100000, -1);
	for (int i = 0; i < n; ++i){
		string s; cin >> s;
		build(s);
	}
	dfs(0);
	if (win[0] && lose[0])
		cout << "First\n";
	else if (win[0] && !lose[0]){
		if (k % 2 == 1)
			cout << "First\n";
		else
			cout << "Second\n";
	}
	else if (!win[0])
		cout << "Second\n";
return 0;}
