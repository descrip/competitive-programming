#include <bits/stdc++.h>
using namespace std;

struct data{
	int a, b, c, d, e;
	data() : a(0), b(0), c(0), d(0), e(0) {}
	data(int A, int B) : a(A), b(B), c(0), d(0), e(0) {}
	data(int A, int B, int C) : a(A), b(B), c(C), d(0), e(0) {}
	data(int A, int B, int C, int D, int E) : a(A), b(B), c(C), d(D), e(E) {}
};

bool operator< (const data &a, const data &b){
	return a.a < b.a;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, T; cin >> N >> T;
	set<data> V, //xcoord add
			  H; //ycoord add id
	vector<data> A (N); //x1 y1 x2 y2 t
	for (int i = 0; i < N; ++i){
		cin >> A[i].a >> A[i].b >> A[i].c >> A[i].d >> A[i].e;
		auto it = H.lower_bound(data(A[i].a, -1));
		if (it == H.end() || it->a != A[i].a)
			H.insert(data(A[i].a, A[i].e, i));
		else{
			data tmp = *it;
			tmp.c += A[i].e;
			H.erase(it);
			H.insert(tmp);
		}
		it = H.lower_bound(data(A[i].c, -1));
		if (it == H.end() || it->a != A[i].c)
			H.insert(data(A[i].c, -A[i].e, i));
		else{
			data tmp = *it;
			tmp.c += A[i].e;
			H.erase(it);
			H.insert(tmp);
		}
		//H.insert(data(A[i].c, -A[i].e, i));
	}
	long long ans = 0;
return 0;}

