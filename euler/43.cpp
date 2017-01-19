#include <bits/stdc++.h>
using namespace std;

bool ok(const vector<int> &v, int l, int r, int d){
	int ret = 0;
	for (int i = l-1; i <= r-1; ++i)
		ret = ret * 10 + v[i];
	return (ret % d == 0);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	long long ans = 0;
	do{
		if (ok(v,2,4,2) && ok(v,3,5,3) && ok(v,4,6,5) && ok(v,5,7,7) && ok(v,6,8,11) && ok(v,7,9,13) && ok(v,8,10,17)){
			long long curr = 0;
			for (int i = 0; i < v.size(); ++i)
				curr = curr * 10 + v[i];
			ans += curr;
		}
	} while (next_permutation(v.begin(), v.end()));
	cout << ans << '\n';
return 0;}

