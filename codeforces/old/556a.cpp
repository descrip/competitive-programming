#include <iostream>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	int a = 0, b = 0;
	for (char c : s)
		if (c == '0')
			++a;
		else
			++b;
	cout << n-2*min(a,b) << '\n';
return 0;}
