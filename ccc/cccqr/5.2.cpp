#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<pair<int, int>> V;
long long ans = 0;

long long calc(long long r, long long c){
	long long ret = 1LL * (N-r+2LL) * (N-r+1LL) / 2LL;
	return max(ret, 0LL);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; ++i){
		int x, y; cin >> x >> y;
		V.push_back({x, y});
	}
	if (M == 2){
		sort(V.begin(), V.end());
		cout << calc(V[0].first, V[0].second) + calc(V[1].first, V[1].second) - calc(V[0].first + V[1].first - V[0].second, V[1].second) << '\n';
		return 0;
	}
	for (int y = 1; y <= N; ++y)
		for (int x = 1; x <= y; ++x){
			for (int j = 0; j < M; ++j)
				if (V[j].first <= y && V[j].second <= x && x <= V[j].second + y - V[j].first){
					++ans;
					break;
				}
		}
	cout << ans << '\n';
return 0;}

