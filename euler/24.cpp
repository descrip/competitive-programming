#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int cnt = 1;
	do{
		++cnt;
		if (cnt == 1000001)
			break;
	} while (next_permutation(v.begin(), v.end()));
	for (int i : v)
		cout << i;
	cout << '\n';
return 0;}

