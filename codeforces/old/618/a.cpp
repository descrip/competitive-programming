#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	while (N > 0){
		cout << (int)log2(N)+1 << ' ';
		N -= (1<<(int)log2(N));
	}
	cout << '\n';
return 0;}

