#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MAXN = 20005, MAXX = 64005;

bool sortVert(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b){
	return a.fi.se < b.fi.se;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, T; cin >> N >> T;
	vector<pair<pair<int,int>, int>> A (N);
	static int B[MAXN], V[MAXN], vid[MAXN];
	for (int i = 0; i < N; ++i){
		cin >> A[i].fi.fi >> A[i].fi.se;
		A[i].fi.fi += 2; A[i].fi.se += 2;
		A[i].se = i+1;
	}
	sort(A.begin(), A.end(), sortVert);
	for (int i = 0; i < N; ++i)
		vid[A[i].se] = i+1;
	sort(A.begin(), A.end());
	int ans = 0xfffffff, x, y;
	for (int i = 0; i < N; ++i){
		for (int j = vid[A[i].se]; j <= MAXN; ++j)
			++V[j];
		int hCnt = 0;
		for (int j = 0; j <= i; ++j){
			if (A[j].fi.se <= A[i].fi.se)
				++B[A[i].se];
			if (A[j].fi.se <= A[i].fi.se)
				++hCnt;
			int tmp;
			if (A[j].fi.se <= A[i].fi.se)
				tmp = V[vid[A[i].se]] - V[vid[A[j].se]-1] - hCnt + B[A[j].se];
			else
				tmp = V[vid[A[j].se]] - V[vid[A[i].se]-1] - B[A[j].se] + hCnt + 1;
			//cout << A[i].fi.fi << ' ' << A[j].fi.fi << ' ' << tmp << ' ' << V[vid[A[j].se]] << ' ' << V[vid[A[i].se]-1] << ' ' << B[A[j].se] << ' ' << hCnt << '\n';
			if (tmp >= T && tmp < ans){
				ans = tmp;
				x = A[i].se;
				y = A[j].se;
			}
		}
	}
	cout << x << ' ' << y << '\n';
return 0;}

