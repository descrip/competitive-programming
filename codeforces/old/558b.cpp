#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	static int a[100000];
	multiset<int> s;
	set<int> s2;
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		s.insert(a[i]);
		s2.insert(a[i]);
	}
	vector<int> ser;
	int most = 0;
	for (int i : s2){
		if (s.count(i) == most)
			ser.push_back(i);
		else if (s.count(i) > most){
			most = s.count(i);
			ser = {i};
		}
	}
	int ans1 = 0, ans2 = 0, ans = 0x7fffffff;
	for (int x : ser){
		int i = 0, j = n-1;
		while (a[i] != x) ++i;
		while (a[j] != x) --j;
		if (j-i+1 < ans){
			ans = j-i+1;
			ans1 = i;
			ans2 = j;
		}
		else if (j-i+1 == ans && i < ans1){
			ans1 = i;
			ans2 = j;
		}
	}
	cout << ans1+1 << ' ' << ans2+1 << '\n';
return 0;}
