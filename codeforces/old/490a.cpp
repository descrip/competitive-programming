#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	queue<int> a, b, c;
	int n; cin >> n;
	for (int i = 1; i <= n; ++i){
		int x; cin >> x;
		if (x == 1) a.push(i);
		else if (x == 2) b.push(i);
		else c.push(i);
	}
	int ans = min(a.size(), min(b.size(), c.size()));
	cout << ans << '\n';
	for (int i = 0; i < ans; ++i){
		cout << a.front() << ' ' << b.front() << ' ' << c.front() << '\n';
		a.pop(); b.pop(); c.pop();
	}
return 0;}
