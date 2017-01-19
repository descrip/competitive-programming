#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1<<21;
const int SIZE = 1<<22;
int up[SIZE], down[SIZE];

void upd(int n, int l, int r, int ul, int ur, int op, int h){
	if (l > r || ur < l || r < ul) return;
	if (ul <= l && r <= ur){
		if (op == 1){
			up[n] = max(up[n],h);
			down[n] = max(down[n],h);
		}
		else if (op == 2){
			up[n] = min(up[n],h);
			down[n] = min(down[n],h);
		}
		return;
	}
	for (int i = 2*n; i <= 2*n+1; ++i){
		down[i] = min(down[i],down[n]);
		down[i] = max(down[i],up[n]);
		up[i] = max(up[i],up[n]);
		up[i] = min(up[i],down[n]);
	}
	down[n] = 0x7FFFFFFF, up[n] = 0;
	upd(2*n,l,l+(r-l)/2,ul,ur,op,h);
	upd(2*n+1,l+(r-l)/2+1,r,ul,ur,op,h);
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 0; i < k; ++i){
		int op, l, r, h; cin >> op >> l >> r >> h;
		upd(1,0,MAXN-1,l,r,op,h);
	}
	for (int j = 1; j < SIZE/2; ++j){
		for (int i = 2*j; i <= 2*j+1; ++i){
			down[i] = min(down[i],down[j]);
			down[i] = max(down[i],up[j]);
			up[i] = max(up[i],up[j]);
			up[i] = min(up[i],down[j]);
		}
	}
	for (int i = SIZE/2; i < SIZE/2+n; ++i)
		cout << min(up[i],down[i]) << '\n';
return 0;}
