#include <bits/stdc++.h>
using namespace std;

struct node{
	int presum, sufsum, maxsum, sum;
	node(int a) : presum(a), sufsum(a), maxsum(a), sum(a) {}
	void merge(const node &l, const node &r){
		sum = l.sum + r.sum;
		presum = max(l.presum, l.sum + r.presum);
		sufsum = max(r.sufsum, l.sufsum + r.sum);
		maxsum = max({presum, sufsum, l.maxsum, r.maxsum, l.sufsum + r.presum});
	}
};

vector<int> arr;
vector<node> tree;

void build(int n, int l, int r){
	if (l > r) return;
	if (l == r){
		tree[n] = node(arr[l]);
		return;
	}
	build(2*n,l,l+(r-l)/2);
	build(2*n+1,l+(r-l)/2+1,r);
	tree[n].merge(tree[2*n],tree[2*n+1]);
}

void update(int n, int l, int r, int x, int v){
	if (!(l <= x && x <= r) || l > r) return;
	if (l == r && l == x){
		tree[n] = node(v);
		return;
	}
	update(2*n,l,l+(r-l)/2,x,v);
	update(2*n+1,l+(r-l)/2+1,r,x,v);
	tree[n].merge(tree[2*n],tree[2*n+1]);
}

node query(int n, int l, int r, int ql, int qr){
	if (l > r || l > qr || r < ql) return node(-10000);
	if (ql <= l && r <= qr) return tree[n];
	node ret = node(0);
	ret.merge(query(2*n,l,l+(r-l)/2,ql,qr),query(2*n+1,l+(r-l)/2+1,r,ql,qr));
	return ret;
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	arr = vector<int> (n);
	for (int i = 0; i < n; ++i) cin >> arr[i];
	tree = vector<node> ((1 << (int)(ceil(log2(n))+1)), node(0));
	build(1,0,n-1);
	int m; cin >> m;
	for (int i = 0; i < m; ++i){
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 0) update(1,0,n-1,x-1,y);
		else cout << query(1,0,n-1,x-1,y-1).maxsum << '\n';
	}
return 0;}
