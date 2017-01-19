#include <bits/stdc++.h>
using namespace std;

int main(){
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	string A[366], E[366];
	getline(cin, A[0]);
	for (int i = 1; i <= N; ++i)
		getline(cin, A[i]);
	fill_n(E, 366, "th");
	E[1] = "st"; E[2] = "nd"; E[3] = "rd";
	for (int i = 1; i <= N; ++i){
		cout << "On the " << i << E[i] << " day of Christmas my true love sent to me:\n";
		for (int j = i; j >= 1; --j){
			if (j == 1 && i != 1)
				cout << "and ";
			cout << j << ' ' << A[j] << '\n';
		}
		if (i != N)
			cout << '\n';
	}
return 0;}

