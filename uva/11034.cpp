#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int c; cin >> c;
	for (int test = 0; test < c; ++test){
		int l, m; cin >> l >> m;
		l *= 100;
		queue<int> left, right;
		for (int i = 0; i < m; ++i){
			int a; string b; cin >> a >> b;
			(b == "right" ? right : left).push(a);
		}
		int cnt = 0; bool bank = false;
		while (!left.empty() || !right.empty()){
			int cl = l;
			while (!(!bank ? left : right).empty() && (!bank ? left : right).front() <= cl){
				cl -= (!bank ? left : right).front();
				(!bank ? left : right).pop();
			}
			++cnt;
			bank = !bank;
		}
		cout << cnt << '\n';
	}
return 0;}
