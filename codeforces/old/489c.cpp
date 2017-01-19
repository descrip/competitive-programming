#include <bits/stdc++.h>
using namespace std;

bool gao(int m, int s){
	return s >= 0 && s <= 9*m;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int m, s; cin >> m >> s;
	if (!gao(m,s)){
		cout << "-1 -1\n";
		return 0;
	}
	else if (m == 1 && s == 0){
		cout << "0 0\n";
		return 0;
	}
	int sum = s;
	string ans = "", ans2 = "";
	for (int i = 0; i < m; ++i)
		for (int j = (i == 0 ? 1 : 0); j <= 9; ++j)
			if (gao(m-i-1,sum-j)){
				ans += (char)('0'+j);
				sum -= j;
				break;
			}
			else if (j == 9){
				cout << "-1 -1\n";
				return 0;
			}
	sum = s;
	for (int i = 0; i < m; ++i)
		for (int j = 9; j >= (i == 0 ? 1 : 0); --j)
			if (gao(m-i-1,sum-j)){
				ans2 += (char)('0'+j);
				sum -= j;
				break;
			}
	cout << ans << ' ' << ans2 << '\n';
return 0;}
