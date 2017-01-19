#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a, b; cin >> a >> b;
	int add = floor((a+b)/(2.0*b)), sub = floor((a-b)/(2.0*b));
	//cout << add << ' ' << sub << '\n';
	if (max(add,sub) < 1){
		cout << "-1\n";
		return 0;
	}
	cout << fixed << setprecision(11) << min((a+b)/(2.0*add), (a-b)/(2.0*sub)) << '\n';
return 0;}
