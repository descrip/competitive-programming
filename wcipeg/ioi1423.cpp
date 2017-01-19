#include <bits/stdc++.h>
using namespace std;

struct node{
	bool act = false; int val = 0, cnt = 0;
}

const int SIZE = (1<<18), MAXN = 100000;
int n, s, d, attr[MAXN], sattr[MAXN];
node tree[SIZE];

void build(int n, int l, int r){
	if (l > r) return;
	if (l == r){
		tree[n].act = true;
		tree[n].val = attr[l];
		tree[n].cnt = 1;
		return;
	}
	build(2*n,l,l+(r-l)/2);
	build(2*n+1,l+(r-l)/2+1,r);
	tree[n].act = true;
	tree[n].val = tree[2*n].val + tree[2*n+1].val;
	tree[n].cnt = tree[2*n].cnt + tree[2*n+1].cnt;
}

int query(int n, int l, int r, int x){
	if (l > r || r < ul || ur < l || x == 0 || tree[n].cnt == 0)
		return 0;
	if (tree[n].cnt > x){
		return query(2*n,l,l+(r-l)/2,tree[n].cnt) +
			query(2*n+1,l+(r-l)/2+1,r,x-tree[n].cnt);
	}
	else return tree[n].val;
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> n >> s >> d;
	for (int i = 0; i < n; ++i)
		cin >> attr[i];

return 0;}
