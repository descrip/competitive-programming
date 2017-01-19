// {{{ Headers 
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>//#include <cstdio>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std; typedef unsigned long ul; typedef long long ll; typedef unsigned long long ull; typedef long double ld; typedef pair<int,int> pii;
#define pb push_back
#define __ << ' ' <<
#define MOD 1000000007
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
// }}}

struct node{
	int minv, gcd, mincnt;
	node(int a) : minv(a), gcd(a), mincnt(1) {}
	void merge(const node &a, const node &b){
		minv = min(a.minv,b.minv);
		gcd = __gcd(a.gcd,b.gcd);
		if (a.minv == b.minv)
			mincnt = a.mincnt + b.mincnt;
		else if (minv == a.minv)
			mincnt = a.mincnt;
		else if (minv == b.minv)
			mincnt = b.mincnt;
	}
};

vector<int> arr;
vector<node> tree;

void build(int n, int l, int r){
	if (l > r) return;
	if (l == r){
		tree[n] = arr[l];
		return;
	}
	build(2*n,l,l+(r-l)/2);
	build(2*n+1,l+(r-l)/2+1,r);
	tree[n].merge(tree[2*n],tree[2*n+1]);
}

void update(int n, int l, int r, int x, int v){
	if (!(l <= x && x <= r)) return;
	if (l == r && l == x){
		tree[n] = node(v);
		return;
	}
	update(2*n,l,l+(r-l)/2,x,v);
	update(2*n+1,l+(r-l)/2+1,r,x,v);
	tree[n].merge(tree[2*n],tree[2*n+1]);
}

//CHECK RANGE
int mquery(int n, int l, int r, int ql, int qr){
	if (l > r || l > qr || r < ql) return 1000000000;
	if (ql <= l && r <= qr) return tree[n].minv;
	return min(mquery(2*n,l,l+(r-l)/2,ql,qr),
		mquery(2*n+1,l+(r-l)/2+1,r,ql,qr));
}

int gquery(int n, int l, int r, int ql, int qr){
	if (l > r || l > qr || r < ql) return -1;
	if (ql <= l && r <= qr) return tree[n].gcd;
	int a = gquery(2*n,l,l+(r-l)/2,ql,qr);
	int b = gquery(2*n+1,l+(r-l)/2+1,r,ql,qr);
	if (a == -1)
		return b;
	else if (b == -1)
		return a;
	else
		return __gcd(a,b);
}

int mcquery(int n, int l, int r, int ql, int qr, int m){
	if (l > r || l > qr || r < ql) return 0;
	if (ql <= l && r <= qr){
		if (tree[n].minv == m)
			return tree[n].mincnt;
		return 0;
	}
	return mcquery(2*n,l,l+(r-l)/2,ql,qr,m) +
		mcquery(2*n+1,l+(r-l)/2+1,r,ql,qr,m);
}

int qquery(int n, int l, int r, int ql, int qr){
	int g = gquery(n,l,r,ql,qr);
	if (g == mquery(n,l,r,ql,qr))
		return mcquery(n,l,r,ql,qr,g);
	return 0;
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	arr = vector<int> (n);
	for (int i = 0; i < n; ++i) cin >> arr[i];
	tree = vector<node> (1 << (int)(ceil(log2(n))+1), node(0));
	build(1,0,n-1);
	for (int i = 0; i < m; ++i){
		char t; int l, r;
		cin >> t >> l >> r;
		if (t == 'C')
			update(1,0,n-1,l-1,r);
		switch (t){
			case 'C':
				update(1,0,n-1,l-1,r);
				break;
			case 'M':
				cout << mquery(1,0,n-1,l-1,r-1) << '\n';
				break;
			case 'G':
				cout << gquery(1,0,n-1,l-1,r-1) << '\n';
				break;
			case 'Q':
				cout << qquery(1,0,n-1,l-1,r-1) << '\n';
				break;
		}
	}
return 0;}
