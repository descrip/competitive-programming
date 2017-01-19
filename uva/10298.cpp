#include <iostream>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	string s, t;
	int ans, i, j;
	static int a[1000001];
	while (true){
		cin >> t;
		s = t+t;
		if (t == ".") break;
		fill(a,a+1000001,0);
		i = 0; j = a[0] = -1;
		while (i < t.size()){
			while (j >= 0 && t[i] != t[j])
				j = a[j];
			++i; ++j; a[i] = j;
		}
		i = j = ans = 0;
		while (i < s.size()){
			while (j >= 0 && s[i] != t[j])
				j = a[j];
			++i; ++j;
			if (j == t.size()){
				++ans; j = a[j];
			}
		}
		cout << ans-1 << '\n';
	}
return 0;}
