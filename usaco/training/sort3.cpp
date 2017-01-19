/*
ID: jezhao11
LANG: C++11
TASK: sort3
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("sort3.in", "r", stdin);
	freopen("sort3.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	static int a[1000], cnt[4];
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		++cnt[a[i]];
	}
	int ans = 0;
	for (int i = 0; i < cnt[1]; ++i)
		if (a[i] != 1){
			++ans;
			if (a[i] == 2){
				for (int j = cnt[1]; j < n; ++j)
					if (a[j] == 1)
						swap(a[i], a[j]);
			}
			else if (a[i] == 3){
				for (int j = n-1; j >= cnt[1]; --j)
					if (a[j] == 1)
						swap(a[i], a[j]);
			}
		}
	/*
	for (int i = 0; i < n; ++i)
		cout << a[i] << " \n"[i==n-1];
	cout << ans << '\n';
	*/
	for (int i = cnt[1]; i < cnt[1]+cnt[2]; ++i)
		if (a[i] != 2){
			++ans;
			for (int j = n-1; j >= 0; --j)
				if (a[j] == 2)
					swap(a[i], a[j]);
		}
	cout << ans << '\n';
return 0;}
