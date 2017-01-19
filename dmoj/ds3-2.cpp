#include <bits/stdc++.h>
using namespace std;

struct node{
	int M, G, MC;
	node (): M(0), G(0), MC(0) {}
	node (int a) : M(a), G(a), MC(1) {}
	void merge(const node &a, const node &b){
		M = min(a.M, b.M);
		G = __gcd(a.G, b.G);
		MC = 0;
		if (M == a.M)
			MC += a.MC;
		if (M == b.M)
			MC += b.MC;
	}
};

int N, M, A[100005];
node tree[3*100005];

void build(int n, int l, int r){
	if (l > r)
		return;
	if (l == r){
		tree[n] = A[l];
		return;
	}
	build(2*n, l, l+(r-l)/2);
	build(2*n+1, l+(r-l)/2+1, r);
	tree[n].merge(tree[2*n], tree[2*n+1]);
}

void update(int n, int l, int r, int x, int v){
	if (l > r || !(l <= x && x <= r))
		return;
	if (l == r && l == x){
		tree[n] = node(v);
		return;
	}
	update(2*n, l, l+(r-l)/2, x, v);
	update(2*n+1, l+(r-l)/2+1, r, x, v);
	tree[n].merge(tree[2*n], tree[2*n+1]);
}

int mquery(int n, int l, int r, int ql, int qr){
	if (l > r || r < ql || qr < l)
		return 1e9;
	if (ql <= l && r <= qr)
		return tree[n].M;
	return min(mquery(2*n, l, l+(r-l)/2, ql, qr), mquery(2*n+1, l+(r-l)/2+1, r, ql, qr));
}

int gquery(int n, int l, int r, int ql, int qr){
	if (l > r || r < ql || qr < l)
		return -1;
	if (ql <= l && r <= qr)
		return tree[n].G;
	int a = gquery(2*n, l, l+(r-l)/2, ql, qr), b = gquery(2*n+1, l+(r-l)/2+1, r, ql, qr);
	if (a == -1)
		return b;
	else if (b == -1)
		return a;
	else
		return __gcd(a, b);
}

int mcquery(int n, int l, int r, int ql, int qr, int m){
	if (l > r || r < ql || qr < l)
		return 0;
	if (ql <= l && r <= qr){
		//cout << l << ' ' << r << ' ' << tree[n].MC << '\n';
		return (tree[n].M == m ? tree[n].MC : 0);
	}
	return mcquery(2*n, l, l+(r-l)/2, ql, qr, m) + mcquery(2*n+1, l+(r-l)/2+1, r, ql, qr, m);
}

int qquery(int n, int l, int r, int ql, int qr){
	int G = gquery(n, l, r, ql, qr), M = mquery(n, l, r, ql, qr);
	if (G == M)
		return mcquery(n, l, r, ql, qr, M);
	else
		return 0;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	build(1, 0, N-1);
	for (int i = 0; i < M; ++i){
		char c; int a, b; cin >> c >> a >> b;
		if (c == 'C')
			update(1, 0, N-1, a-1, b);
		else if (c == 'M')
			cout << mquery(1, 0, N-1, a-1, b-1) << '\n';
		else if (c == 'G')
			cout << gquery(1, 0, N-1, a-1, b-1) << '\n';
		else if (c == 'Q')
			cout << qquery(1, 0, N-1, a-1, b-1) << '\n';
	}
return 0;}

