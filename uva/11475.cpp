#include <algorithm>
#include <iostream>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	string s, t;
	int i, j;
	static int a[100000];
	while (cin >> s){
		t = s;
		reverse(t.begin(),t.end());
		i = 0; j = a[0] = -1;
		while (i < t.size()){
			if (j >= 0 && t[i] != t[j])
				j = a[j];
			++i; ++j; a[i] = j;
		}
		i = j = 0;
		while (i < s.size()){
			while (j >= 0 && s[i] != t[j])
				j = a[j];
			++i; ++j;
		}
		cout << s << t.substr(j,t.size()-j) << '\n';
	}
return 0;}
