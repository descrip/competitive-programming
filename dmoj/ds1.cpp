#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, M;
ll A[100005], B[100005], C[100005];

ll rsq(ll z[], int a){
	ll ret = 0;
	for (; a; a -= (a & -a))
		ret += z[a];
	return ret;
}

void add(ll z[], int n, int a, ll b){
	for (; a <= n; a += (a & -a))
		z[a] += b;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i){
		cin >> C[i];
		add(A, N, i, C[i]);
		add(B, 100001, C[i], 1);
	}
	for (int i = 0; i < M; ++i){
		char c; cin >> c;
		if (c == 'C'){
			int pos; ll val; cin >> pos >> val;
			add(A, N, pos, val - C[pos]);
			add(B, 100001, C[pos], -1);
			add(B, 100001, val, 1);
			C[pos] = val;
		}
		else if (c == 'S'){
			int l, r; cin >> l >> r;
			cout << rsq(A, r) - (l == 1 ? 0 : rsq(A, l-1)) << '\n';
		}
		else if (c == 'Q'){
			ll x; cin >> x;
			cout << rsq(B, x) << '\n';
		}
	}
return 0;}

