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

#include "secret.h"

vector<int> arr, tree;

void build(int n, int l, int r){
	if (l > r) return;
	if (l == r){
		tree[n] = arr[l];
		return;
	}
	build(2*n,l,l+(r-l)/2);
	build(2*n+1,l+(r-l)/2+1,r);
	tree[n] = Secret(tree[2*n],tree[2*n+1]);
}

void Init(int N, int A[]){
	arr = vector<int> (A,A+N);
	tree = vector<int> ((1 << (int)(ceil(log2(N)+1))));
	build(1,0,N-1);
}

int find(int n, int l, int r, int ql, int qr){
	if (l > r || l > qr || r < ql) return -1;
	if (ql <= l && r <= qr) return tree[n];
	int a = find(2*n,l,l+(r-l)/2,ql,qr);
	int b = find(2*n+1,l+(r-l)/2+1,r,ql,qr);
	if (a == -1) return b;
	else if (b == -1) return a;
	else return Secret(a,b);
}

int Query(int L, int R){
	return find(1,0,arr.size()-1,L,R);
}
