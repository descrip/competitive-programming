#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main(){
	int n, p, c = 0, d = 1; cin >> n >> p;
	vector<pair<int,int>> v;
	for (int i = 1; i <= n; ++i){
		int a, b; cin >> a >> b;
		if (i == p) c = a;
		else if (a >= b) v.push_back({b,a});
	}
	int ac = c, ad = 1;
	sort(v.begin(),v.end());
	for (int i = 0; i < v.size(); ++i){
		if (v[i].first <= c){
			c += v[i].second - v[i].first;
			++d;
			if (c > ac || (c == ac && d > ad)){
				ac = c; ad = d;
			}
		}
		else break;
	}
	cout << ac << '\n' << ad << '\n';
}
