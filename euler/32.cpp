#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	set<int> ans;
	do{
		for (int i = 0; i < 7; ++i)
			for (int j = i+1; j < 8; ++j){
				int x = 0, y = 0, z = 0;
				for (int k = 0; k <= i; ++k)
					x = x * 10 + a[k];
				for (int k = i+1; k <= j; ++k)
					y = y * 10 + a[k];
				for (int k = j+1; k < 9; ++k)
					z = z * 10 + a[k];
				if (x * y == z)
					ans.insert(z);
			}
	} while (next_permutation(a.begin(), a.end()));
	int all = 0;
	for (int i : ans)
		all += i;
	cout << all << '\n';
return 0;}

