#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;
int M, N, Q, arr[MAXN], tree[3*MAXN], lazy[3*MAXN];

void build(int n, int l, int r){
	if (l > r) return;
	if (l == r){
		tree[n] = arr[l] % M;
		return;
	}
	build(2*n, l, l+(r-l)/2);
	build(2*n+1, l+(r-l)/2+1, r);
	tree[n] = (tree[2*n] + tree[2*n+1]) % M;
}

void upd(int n, int l, int r, int ul, int ur, int x){
	if (lazy[n]){
		tree[n] += (r-l+1) * lazy[n];
		tree[n] %= M;
		if (l != r){
			lazy[2*n] += lazy[n];
			lazy[2*n+1] += lazy[n];
			lazy[2*n] %= M;
			lazy[2*n+1] %= M;
		}
		lazy[n] = 0;
	}
	if (l > r || ur < l || r < ul) return;
	if (ul <= l && r <= ur){
		tree[n] += ((r-l+1) % M) * x;
		tree[n] %= M;
		if (l != r){
			lazy[2*n] += x;
			lazy[2*n+1] += x;
			lazy[2*n] %= M;
			lazy[2*n+1] %= M;
		}
		return;
	}
	upd(2*n, l, l+(r-l)/2, ul, ur, x);
	upd(2*n+1, l+(r-l)/2+1, r, ul, ur, x);
	tree[n] = (tree[2*n] + tree[2*n+1]) % M;
}

int query(int n, int l, int r, int ql, int qr){
	if (lazy[n]){
		tree[n] += ((r-l+1) % M) * lazy[n];
		tree[n] %= M;
		if (l != r){
			lazy[2*n] += lazy[n];
			lazy[2*n+1] += lazy[n];
			lazy[2*n] %= M;
			lazy[2*n+1] %= M;
		}
		lazy[n] = 0;
	}
	if (l > r || qr < l || r < ql) return 0;
	else if (ql <= l && r <= qr) return tree[n];
	else return (query(2*n, l, l+(r-l)/2, ql, qr) + query(2*n+1, l+(r-l)/2+1, r, ql, qr)) % M;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> M >> N >> Q;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	build(1, 0, N-1);
	for (int i = 0; i < Q; ++i){
		int t; cin >> t;
		if (t == 1){
			int l, r, x; cin >> l >> r >> x;
			upd(1, 0, N-1, l-1, r-1, x);
		}
		else if (t == 2){
			int l, r; cin >> l >> r;
			cout << query(1, 0, N-1, l-1, r-1) << '\n';
		}
	}
return 0;}
