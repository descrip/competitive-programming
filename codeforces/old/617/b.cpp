#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	vector<int> cnt;
	int last = -1;
	for (int i = 0; i < N; ++i){
		int a; cin >> a;
		//cout << a << ' ' << last << '\n';
		if (a == 0)
			continue;
		if (last == -1)
			last = i;
		else{
			cnt.push_back(i-last);
			last = i;
		}
	}
	if (last == -1){
		cout << 0 << '\n';
		return 0;
	}
	long long ans = 1;
	for (int i = 0; i < cnt.size(); ++i)
		ans *= cnt[i];
	cout << ans << '\n';
return 0;}

