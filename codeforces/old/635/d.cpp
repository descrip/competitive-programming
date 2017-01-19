#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
int N, K, A, B, Q, bad[MAXN], good[MAXN];

int sum(int a[], int i){
	int ret = 0;
	while (i > 0){
		ret += a[i];
		i -= (i & -i);
	}
	return ret;
}

void add(int a[], int i, int k){
	while (i < MAXN){
		a[i] += k;
		i += (i & -i);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K >> A >> B >> Q;
	for (int q = 0; q < Q; ++q){
		int t; cin >> t;
		if (t == 1){
			int d, a; cin >> d >> a;

			int tmp = sum(bad, d) - sum(bad, d-1);
			if (tmp != B)
				add(bad, d, min(a + tmp, B) - tmp);

			tmp = sum(good, d) - sum(good, d-1);
			//cout << min(a + tmp, A) << '\n';
			if (tmp != A)
				add(good, d, min(a + tmp, A) - tmp);
		}
		else{
			int p; cin >> p;
			cout << sum(bad, p-1) + sum(good, MAXN-1) - sum(good, p+K-1) << '\n';
		}
	}
	/*
	for (int i = 1; i <= N; ++i)
		cout << sum(bad, i) - sum(bad, i-1) << ' ';
	cout << '\n';
	for (int i = 1; i <= N; ++i)
		cout << sum(good, i) - sum(good, i-1) << ' ';
	cout << '\n';
	*/
return 0;}

