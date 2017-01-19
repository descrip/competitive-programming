#include <bits/stdc++.h>
using namespace std;

struct apple{
	string name;
	int val, cost, vol;
	apple(string s, int a, int b, int c) : name(s), val(a), cost(b), vol(c) {}
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, R, S; cin >> N >> R >> S;
	static int dp[10001][10001];
	vector<apple> A;
	for (int i = 0; i < N; ++i){
		string s; int v, a, b;
		cin >> s >> v >> a >> b;
		A.push_back(apple(s,v,a,b));
	}
	for (int r = 0; r <= R; ++r)
		for (int s = 0; s <= S; ++s)
			for (int i = 0; i < A.size(); ++i)
				if (A[i].cost <= r && A[i].vol <= s)
					dp[r][s] = max(dp[r][s], dp[r-A[i].cost][s-A[i].vol] + A[i].val);
	vector<int> ans (N);
	int r = R, s = S;
	cout << dp[r][s] << '\n';
	while (dp[r][s] > 0){
		vector<int> aux (N);
		int ind = 0;
		for (int i = 0; i < N; ++i)
			if (A[i].cost <= r && A[i].vol <= s && dp[r-A[i].cost][s-A[i].vol] + A[i].val == dp[r][s]){
				ind = i;
				break;
			}
		++ans[ind];
		r -= A[ind].cost;
		s -= A[ind].vol;
	}
	for (int i = 0; i < N; ++i)
		cout << A[i].name << ' ' << ans[i] << '\n';
return 0;}
