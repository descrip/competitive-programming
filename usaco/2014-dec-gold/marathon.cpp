#include <bits/stdc++.h>
using namespace std;

const int MAXNQ = 100000, SIZE = (1<<18);
int dist[SIZE], skip[SIZE], cpx[MAXNQ], cpy[MAXNQ], N, Q, ql, qr, qx;

inline int manhat(int x1, int y1, int x2, int y2){
	return abs(x1-x2) + abs(y1-y2);
}

void build(int n, int l, int r){
	if (l > r) return;
	if (l == r){
		if (l < N-1){
			dist[n] = manhat(cpx[l],cpy[l],cpx[l+1],cpy[l+1]);
			if (l < N-2)
				skip[n] = manhat(cpx[l],cpy[l],cpx[l+1],cpy[l+1])
					+ manhat(cpx[l+1],cpy[l+1],cpx[l+2],cpy[l+2])
					- manhat(cpx[l],cpy[l],cpx[l+2],cpy[l+2]);
			return;
		}
		else return;
	}
	build(2*n,l,l+(r-l)/2);
	build(2*n+1,l+(r-l)/2+1,r);
	dist[n] = dist[2*n] + dist[2*n+1];
	skip[n] = max(skip[2*n],skip[2*n+1]);
}

int querydist(int n, int l, int r){
	if (l > r || r < ql || qr < l) return 0;
	if (ql <= l && r <= qr)
		return dist[n];
	return querydist(2*n,l,l+(r-l)/2) + querydist(2*n+1,l+(r-l)/2+1,r);
}

int queryskip(int n, int l, int r){
	if (l > r || r < ql || qr < l) return 0;
	if (ql <= l && r <= qr)
		return skip[n];
	return max(queryskip(2*n,l,l+(r-l)/2),queryskip(2*n+1,l+(r-l)/2+1,r));
}

void upddist(int n, int l, int r){
	if (l > r || !(l <= qx && qx <= r)) return;
	if (l == r && l == qx){
		if (l < N-1)
			dist[n] = manhat(cpx[l],cpy[l],cpx[l+1],cpy[l+1]);
		return;
	}
	upddist(2*n,l,l+(r-l)/2);
	upddist(2*n+1,l+(r-l)/2+1,r);
	dist[n] = dist[2*n] + dist[2*n+1];
}

void updskip(int n, int l, int r){
	if (l > r || !(l <= qx && qx <= r)) return;
	if (l == r && l == qx){
		if (l < N-2)
			skip[n] = manhat(cpx[l],cpy[l],cpx[l+1],cpy[l+1])
				+ manhat(cpx[l+1],cpy[l+1],cpx[l+2],cpy[l+2])
				- manhat(cpx[l],cpy[l],cpx[l+2],cpy[l+2]);
		return;
	}
	updskip(2*n,l,l+(r-l)/2);
	updskip(2*n+1,l+(r-l)/2+1,r);
	skip[n] = max(skip[2*n],skip[2*n+1]);
}

int main(){
	ifstream fin ("marathon.in");
	fin >> N >> Q;
	for (int i = 0; i < N; ++i)
		fin >> cpx[i] >> cpy[i];
	build(1,0,N-1);
	ofstream fout ("marathon.out");
	for (int i = 0; i < Q; ++i){
		char c; fin >> c;
		if (c == 'Q'){
			fin >> ql >> qr;
			--ql; qr -= 2;
			int a = querydist(1,0,N-1);
			--qr;
			int b = queryskip(1,0,N-1);
			fout << a-b << '\n';
		}
		else if (c == 'U'){
			int x, y; fin >> qx >> x >> y;
			--qx;
			cpx[qx] = x;
			cpy[qx] = y;
			upddist(1,0,N-1);
			--qx;
			upddist(1,0,N-1);
			--qx;
			updskip(1,0,N-1);
			++qx;
			updskip(1,0,N-1);
			++qx;
			updskip(1,0,N-1);
		}
	}
	fin.close();
	fout.close();
return 0;}
