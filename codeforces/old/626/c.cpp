#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M; cin >> N >> M;
	ll A = 2LL*N, B = 3LL*M;
	for (ll i = 6LL; i <= max(A, B); i += 6LL){
		if (A+2 <= B+3)
			A += 2;
		else
			B += 3;
	}
	cout << max(A, B) << '\n';
return 0;}

