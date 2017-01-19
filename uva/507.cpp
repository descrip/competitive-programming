#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int ts; cin >> ts;
	for (int tc = 1; tc <= ts; ++tc){
		int s; cin >> s;
		int end = 0, far = 0, a = 0, b = 0, last = 0;
		for (int i = 1; i < s; ++i){
			int x; cin >> x;
			end += x;
			//cout << ' ' << end << ' ' << far << '\n';
			if (end > far || (far == end && i - last > b - a)){
				far = end;
				b = i;
				a = last;
			}
			if (end < 0){
				end = 0;
				last = i;
			}
		}
		if (far > 0)
			cout << "The nicest part of route " << tc << " is between stops " << a+1 << " and " << b+1 << '\n';
		else 
			cout << "Route " << tc << " has no nice parts\n";
	}
return 0;}
