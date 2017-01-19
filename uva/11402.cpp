#include <bits/stdc++.h>
using namespace std;

const int MAX = 1024000, LOGMAX = 1<<(int)(ceil(log2(MAX))+1)+1,
	  LPN = 0, LPF = 1, LPE = 2, LPI = 3;
bool arr[MAX];
int tree[LOGMAX], lazy[LOGMAX];
int mix[4][4] = {{0,1,2,3},{1,1,1,1},{2,2,2,2},{3,2,1,0}};

void build(int n, int l, int r){
	if (l > r) return;
	if (l == r){
		tree[n] = arr[l]; return;
	}
	build(2*n,l,l+(r-l)/2);
	build(2*n+1,l+(r-l)/2+1,r);
	tree[n] = tree[2*n] + tree[2*n+1];
}

void prop(int n, int l, int r){
	switch (lazy[n]){
		case LPF:
			tree[n] = r-l+1; break;
		case LPE:
			tree[n] = 0; break;
		case LPI:
			tree[n] = r-l+1-tree[n]; break;
	}
	if (l != r){
		lazy[2*n] = mix[lazy[n]][lazy[2*n]];
		lazy[2*n+1] = mix[lazy[n]][lazy[2*n+1]];
	}
	lazy[n] = LPN;
}

void upd(int n, int l, int r, int ul, int ur, int v){
	prop(n,l,r);
	if (l > r || ur < l || r < ul) return;
	if (ul <= l && r <= ur){
		lazy[n] = v;
		prop(n,l,r);
		return;
	}
	upd(2*n,l,l+(r-l)/2,ul,ur,v);
	upd(2*n+1,l+(r-l)/2+1,r,ul,ur,v);
	tree[n] = tree[2*n] + tree[2*n+1];
}

int query(int n, int l, int r, int ql, int qr){
	prop(n,l,r);
	if (l > r || qr < l || r < ql) return 0;
	if (ql <= l && r <= qr) return tree[n];
	else return query(2*n,l,l+(r-l)/2,ql,qr) + query(2*n+1,l+(r-l)/2+1,r,ql,qr);
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	for (int test = 1; test <= t; ++test){
		cout << "Case " << test << ":\n";
		int m; cin >> m;
		int arrlen = 0;
		for (int i = 0; i < m; ++i){
			int a; string s; cin >> a >> s;
			for (int j = 0; j < a; ++j)
				for (int k = 0; k < s.size(); ++k)
					arr[arrlen++] = s[k] - '0';
		}
		build(1,0,arrlen-1);
		fill(lazy,lazy+LOGMAX,0);
		int q; cin >> q;
		int numq = 1;
		for (int i = 0; i < q; ++i){
			char c; int a, b; cin >> c >> a >> b;
			switch (c){
				case 'F':
					upd(1,0,arrlen-1,a,b,LPF); break;
				case 'E':
					upd(1,0,arrlen-1,a,b,LPE); break;
				case 'I':
					upd(1,0,arrlen-1,a,b,LPI); break;
				case 'S':
					cout << "Q" << numq++ << ": " << query(1,0,arrlen-1,a,b) << '\n'; break;
			}
		}
	}
return 0;}
