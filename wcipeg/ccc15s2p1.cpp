#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, W; cin >> N >> W;
	vector<int> T (N);
	for (int i = 0; i < N; ++i)
		cin >> T[i];
	long long ans1 = 0, ans2 = 0, ans3 = 0;
	sort(T.begin(), T.end());

	if (W < T[0])
		ans1 = T[N-1] - W;
	else if (W > T[N-1])
		ans1 = W - T[0];
	else
		ans1 = T[N-1] - T[0];

	int last = W;
	bool coin = true;
	deque<int> dq1 (T.begin(), T.end()), dq2 = dq1;
	while (!dq1.empty()){
		if (coin){
			ans2 += max(abs(dq1.back() - W), abs(dq1.back() - last));
			last = dq1.back();
			dq1.pop_back();
		}
		else{
			ans2 += max(abs(dq1.front() - W), abs(dq1.front() - last));
			last = dq1.front();
			dq1.pop_front();
		}
		coin = !coin;
	}

	last = W;
	coin = false;
	while (!dq2.empty()){
		if (coin){
			ans3 += max(abs(dq2.back() - W), abs(dq2.back() - last));
			last = dq2.back();
			dq2.pop_back();
		}
		else{
			ans3 += max(abs(dq2.front() - W), abs(dq2.front() - last));
			last = dq2.front();
			dq2.pop_front();
		}
		coin = !coin;
	}

	cout << ans1 << ' ' << max(ans2, ans3) << '\n';
return 0;}

