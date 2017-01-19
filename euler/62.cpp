#include <bits/stdc++.h>
using namespace std;

short cnt[100000];

long long smallPerm(long long n){
	vector<int> v;
	while (n > 0){
		v.push_back(n % 10);
		n /= 10;
	}
	sort(v.begin(), v.end());
	long long ret = 1;
	for (int i = 0; i < v.size(); ++i)
		ret = ret * 10 + v[i];
	return ret;
}

int main(){
	//ios_base::sync_with_stdio(0); cin.tie(0);
	long long n = 345;
	map<long long, int> m;
	while (++n){
		long long a = smallPerm(n*n*n);
		if (m.count(a) == 0)
			m[a] = n;
		++cnt[m[a]];
		if (cnt[m[a]] == 5){
			cout << (long long)m[a]*m[a]*m[a] << '\n';
			return 0;
		}
	}
return 0;}

