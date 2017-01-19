#include <bits/stdc++.h>
using namespace std;

vector<int> pset, setrank;
void init(int n){
	pset.assign(n+1,0);
	for (int i = 1; i <= n; ++i) pset[i] = i;
	setrank.assign(n+1,1);
}
int findset(int n){
	return (pset[n] == n) ? n : (pset[n] = findset(pset[n]));
}
void unionset(int a, int b){
	if (findset(a) == findset(b)) return;
	int x = findset(a), y = findset(b);
	if (setrank[x] > setrank[y])
		pset[y] = x;
	else{
		pset[x] = y;
		if (setrank[x] == setrank[y]) ++setrank[y];
	}
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	init(n);
	int cnt = 0;
	vector<int> ans;
	for (int i = 1; i <= m; ++i){
		int a, b; cin >> a >> b;
		if (findset(a) != findset(b)){
			unionset(a,b);
			ans.push_back(i);
			++cnt;
		}
	}
	if (cnt != n-1) cout << "Disconnected Graph" << '\n';
	else{
		for (int i : ans) cout << i << '\n';
	}
return 0;}
