#include <bits/stdc++.h>
using namespace std;

int n, num;
vector<int> a, nodes;

long long recur(int p){
	if ((1 << n) <= p && p <= (1 << (n+1)) - 1) return 0;
	else{
		long long ret = (long long) recur(2*p) + recur(2*p+1);
		nodes[p] = max(a[2*p-1] + nodes[2*p],a[2*p] + nodes[2*p+1]);
		//cout << p << ' ' << nodes[2*p] << ' ' << nodes[2*p+1] << ' ' << ret + abs(a[2*p-1] + nodes[2*p] - a[2*p] - nodes[2*p+1]) << '\n';
		return ret + abs(a[2*p-1] + nodes[2*p] - a[2*p] - nodes[2*p+1]);
	}
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> n;
	num = (1 << (n+1)) - 1;
	a.push_back(0);
	for (int i = 0; i < num-1; ++i){
		int x; cin >> x;
		a.push_back(x);
	}
	nodes.assign(num+1,0);
	cout << recur(1) << '\n';
return 0;}
