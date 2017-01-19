#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int x; cin >> x;
	string s; cin >> s >> s;
	int ans = 0;
	if (s == "week"){
		--x;
		for (int i = 0; i < 366; ++i)
			if ((4+i) % 7 == x)
				++ans;
	}
	else{
		if (x == 31)
			ans = 7;
		else if (x == 30)
			ans = 11;
		else
			ans = 12;
	}
	cout << ans << '\n';
return 0;}

