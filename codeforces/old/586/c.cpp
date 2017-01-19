#include <bits/stdc++.h>
using namespace std;

struct kid{
	long long r, v, d, p;
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<kid> v (n);
	for (int i = 0; i < n; ++i){
		cin >> v[i].v >> v[i].d >> v[i].p;
		v[i].r = i+1;
	}
	vector<int> ans;
	while (!v.empty()){
		kid curr = v[0];
		v.erase(v.begin());
		ans.push_back(curr.r);
		long long sub2 = 0;
		for (int i = 0; i < v.size(); ++i){
			v[i].p -= curr.v + sub2;
			curr.v = max(curr.v-1, 0LL);
			if (v[i].p < 0)
				sub2 += v[i].d;
		}
		for (int i = v.size()-1; i >= 0; --i)
			if (v[i].p < 0)
				v.erase(v.begin()+i);
	}
	cout << ans.size() << '\n';
	for (int i : ans)
		cout << i << ' ';
	cout << '\n';
return 0;}
