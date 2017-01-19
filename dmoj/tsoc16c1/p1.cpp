#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	for (int i = 0; i < N; ++i){
		int L, A, B, F; cin >> L >> A >> B >> F;
		if (A <= (L-F) && (L-F) <= B)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
return 0;}

