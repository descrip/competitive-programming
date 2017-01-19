#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50000;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	static pair<int,int> a[MAXN], b[MAXN];
	for (int i = 0; i < n; ++i){
		int x, y; cin >> x >> y;
		a[i] = {x,y};
	}
	for (int i = 0; i < n; ++i){
		int x, y; cin >> x >> y;
		b[i] = {x,y};
	}
return 0;}
