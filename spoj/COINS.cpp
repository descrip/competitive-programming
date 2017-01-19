#include <bits/stdc++.h>
using namespace std;

map<int, long long> m;

long long recur(int n){
	if (m[n] != 0)
		return m[n];
	else if (n == 0)
		return 0;
	else{
		m[n] = recur(n/4) + recur(n/3) + recur(n/2);
		return m[n];
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 1; i < 12; ++i)
		m[i] = i;
	m[12] = 13;
	int a;
	while (cin >> a)
		cout << recur(a) << '\n';
return 0;}

