#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	vector<int> a; int x;
	while (cin >> x) a.push_back(x);
	vector<int> dp (a.size(),-0xFFFFFFF), id (a.size());
	int pos = 0, len = 0;
	for (int i = 0; i < a.size(); ++i){
		pos = lower_bound(dp.begin(),dp.begin()+len,a[i]) - dp.begin();
		dp[pos] = a[i];
		if (pos == len) ++len;
		id[i] = pos;
	}
	cout << len-- << "\n-\n";
	stack<int> ans;
	for (int i = id.size()-1; i >= 0; --i){
		if (id[i] == len){
			ans.push(a[i]);
			--len;
		}
	}
	while (!ans.empty()){
		cout << ans.top() << '\n';
		ans.pop();
	}
return 0;}
