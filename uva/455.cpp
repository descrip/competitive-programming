#include <iostream>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int N, i, j, ans; cin >> N;
	string s, t;
	static int a[81];
	for (int z = 0; z < N; ++z){
		cin >> t;
		s = t+t;
		fill(a,a+81,0);
		i = 0; j = a[0] = -1;
		while (i < t.size()){
			while (j >= 0 && t[i] != t[j]) j = a[j];
			++i; ++j; a[i] = j;
		}
		i = j = ans = 0;
		while (i < s.size()){
			while (j >= 0 && s[i] != t[j]) j = a[j];
			++i; ++j;
			if (j == t.size()){
				j = a[j];
				++ans;
			}
		}
		cout << t.size()/(ans-1) << '\n';
		if (z != N-1) cout << '\n';
	}
return 0;}
