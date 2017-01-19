#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int dd = 0, d = 0, m = 0, y = 1900;
	vector<int> md = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int ans = 0;
	while (!(d == 0 && m == 0 && y == 2001)){
		if (y >= 1901 && dd == 6 && d == 0)
			++ans;
		dd = (dd + 1) % 7;
		++d;
		if (d == md[m]){
			d = 0;
			++m;
			if (m == 12){
				m = 0;
				++y;
				if (y % 400 == 0)
					md[1] = 29;
				else if (y % 100 == 0)
					md[1] = 28;
				else if (y % 4 == 0)
					md[1] = 29;
				else
					md[1] = 28;
			}
		}
	}
	cout << ans << '\n';
return 0;}

