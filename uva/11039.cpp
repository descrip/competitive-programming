#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int ts; cin >> ts;
	set<int> red, blue, red1, blue1;
	for (int tc = 0; tc < ts; ++tc){
		int n; cin >> n;
		red.clear(); blue.clear();
		for (int i = 0; i < n; ++i){
			int a; cin >> a;
			if (a < 0) red.insert(-a);
			else blue.insert(a);
		}
		red1 = red; blue1 = blue;
		bool floor = true; //if red
		int last = 0;
		while (true){
			if (blue1.lower_bound(
		}
	}
return 0;}
