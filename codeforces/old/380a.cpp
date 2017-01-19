#include <bits/stdc++.h>
using namespace std;

const int MAXM = 100000;
int m, x[MAXM], l[MAXM], c[MAXM], y[MAXM];
vector<long long> h = {1};
long long pos = 1;

int solve(long long pos){
	auto it = upper_bound(h.begin(), h.end(), pos) - h.begin() - 1;
	if (x[it] == 1)
		return y[it];
	else
		return solve((pos - h[it]) % l[it] + 1);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> m;
	for (int i = 0; i < m; ++i){
		cin >> x[i];
		if (x[i] == 1){
			cin >> y[i];
			++pos;
		}
		else{
			cin >> l[i] >> c[i];
			pos += (long long) l[i] * c[i];
		}
		h.push_back(pos);
	}
	int q; cin >> q;
	for (int i = 0; i < q; ++i){
		long long a; cin >> a;
		cout << solve(a) << " \n"[i==q-1];
	}
return 0;}

