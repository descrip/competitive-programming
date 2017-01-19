#include <bits/stdc++.h>
using namespace std;

int main(){
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int tc; cin >> tc;
	static char a[3][105];
	for (int ts = 0; ts < tc; ++ts){
		int n, k; cin >> n >> k;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 105; ++j)
				a[i][j] = '.';
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < n; ++j)
				cin >> a[i][j];
		vector<bool> ok (3), okf (3);
		for (int i = 0; i < 3; ++i)
			if (a[i][0] == 's'){
				ok[i] = true;
				a[i][0] = '.';
				break;
			}
		int os = 0;
		for (int i = 0; i < n; ++i){
			if (os+i > n)
				break;
			//cout << ok[0] << ' ' << ok[1] << ' ' << ok[2] << '\n';
			for (int j = 0; j < 3; ++j)
				if (ok[j] && a[j][os+i] == '.' && a[j][os+i+1] == '.'){
					okf[j] = true;
					if (j != 0)
						okf[j-1] = true && (a[j-1][os+i+1] == '.');
					if (j != 2)
						okf[j+1] = true && (a[j+1][os+i+1] == '.');
				}
			ok = okf;
			okf = {0,0,0};
			os += 2;
		}
		for (int i = 0; i < 3; ++i){
			if (ok[i]){
				cout << "YES\n";
				break;
			}
			else if (i == 2)
				cout << "NO\n";
		}
	}
return 0;}
