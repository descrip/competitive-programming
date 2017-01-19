#include <bits/stdc++.h>
using namespace std;

long long N, M;
vector<pair<long long, long long>> V;

long long calc(long long r, long long c){
	long long ret = 1LL * (N-r+2LL) * (N-r+1LL) / 2LL;
	return max(ret, 0LL);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	assert(M == 2);
	for (long long i = 0LL; i < M; ++i){
		long long x, y; cin >> x >> y;
		V.push_back({x, y});
	}
	sort(V.begin(), V.end());
	cout << calc(V[0].first, V[0].second) + calc(V[1].first, V[1].second) - calc(V[0].first + V[1].first - V[0].second, V[1].second) << '\n';
return 0;}
