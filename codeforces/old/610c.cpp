#include <bits/stdc++.h>
using namespace std;

int k;
static char a[10][512][512];

void recur(int k){
	if (k == 0){
		a[0][0][0] = '+';
		return;
	}
	recur(k-1);
	for (int y = 0; y < (1<<(k-1)); ++y)
		for (int x = 0; x < (1<<(k-1)); ++x)
			if (a[k-1][y][x] == '+'){
				a[k][y*2][x*2] = '+';
				a[k][y*2+1][x*2] = '+';
				a[k][y*2][x*2+1] = '+';
				a[k][y*2+1][x*2+1] = '*';
			}
			else{
				a[k][y*2][x*2] = '*';
				a[k][y*2+1][x*2] = '*';
				a[k][y*2][x*2+1] = '*';
				a[k][y*2+1][x*2+1] = '+';
			}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> k;
	recur(k);
	for (int y = 0; y < (1<<k); ++y){
		for (int x = 0; x < (1<<k); ++x)
			cout << a[k][y][x];
		cout << '\n';
	}
return 0;}

