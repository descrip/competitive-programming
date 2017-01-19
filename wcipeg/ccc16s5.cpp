#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, T;
bool A[100005], B[100005];

ll zmod(ll a, ll b){
	return ((a % b) + b) % b;
}

void recur(){
	if (T == 0)
		return;
	ll t = (1LL << (ll)log2((long double)T));
	for (ll i = 0; i < N; ++i)
		B[i] = A[zmod(i-t, N)] ^ A[zmod(i+t, N)];
	T -= t;
	for (ll i = 0; i < N; ++i)
		A[i] = B[i];
	recur();
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> T;
	for (ll i = 0; i < N; ++i){
		char c; cin >> c;
		A[i] = (c == '1');
	}
	recur();
	for (int i = 0; i < N; ++i)
		cout << B[i];
	cout << '\n';
return 0;}

