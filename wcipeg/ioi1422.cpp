#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	static int host[MAXN], prot[MAXN];
	static pair<int,int> node[MAXN];
	for (int i = 0; i < n; ++i)
		cin >> node[i].first;
	for (int i = 1; i < n; ++i)
		cin >> host[i] >> prot[i];
	for (int i = n-1; i > 0; --i){
		int h0 = node[host[i]].first,
			h1 = node[host[i]].second,
			n0 = node[i].first,
			n1 = node[i].second;
	}
	cout << max(node[0].first, node[0].second) << '\n';
return 0;}

