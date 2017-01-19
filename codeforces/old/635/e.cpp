#include <bits/stdc++.h>
using namespace std;

const int MAXM = 200005;
#define fi first
#define se second

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int D, N, M; cin >> D >> N >> M;

	static pair<int, int> arr[MAXM];
	for (int i = 1; i <= M; ++i)
		cin >> arr[i].fi >> arr[i].se;
	M += 2;
	arr[0].se = 0xfffffff;
	arr[M-1].se = -1;
	arr[M-1].fi = D;
	sort(arr, arr+M);

	for (int i = 0; i < M-1; ++i)
		if (arr[i+1].fi - arr[i].fi > N){
			cout << "-1\n";
			return 0;
		}

	static int next[MAXM];
	fill_n(next, MAXM, -1);
	vector<pair<int, int>> S;
	for (int i = 0; i < M; ++i){
		while (!S.empty() && S.back().fi > arr[i].se){
			next[S.back().se] = i;
			S.pop_back();
		}
		S.push_back({arr[i].se, i});
	}

	/*
	for (int i = 0; i < M; ++i)
		cout << next[i] << '\n';
		*/

	int fuel = N;
	long long ans = 0;
	for (int i = 0; i < M-1; ++i){
		int d = (next[i] == -1 ? 0xfffffff : arr[next[i]].fi - arr[i].fi);
		if (min(N, d) > fuel){
			ans += (long long) (min(N, d) - fuel) * arr[i].se;
			fuel = min(N, d);
		}
		//cout << i << ' ' << fuel << '\n';
		fuel -= arr[i+1].fi - arr[i].fi;
	}
	cout << ans << '\n';
return 0;}

