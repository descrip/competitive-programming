#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long R, L, B; cin >> R >> L >> B;
	vector<long long> arr(R), psr(R), psl(R);
	for (int i = 0; i < R; ++i)
		cin >> arr[i];
	psr[0] = arr[0];
	for (int i = 1; i < R; ++i)
		psr[i] = psr[i-1] + arr[i];
	psl[R-1] = arr[R-1];
	for (int i = R-2; i >= 0; --i)
		psl[i] = psl[i+1] + (L - arr[i]);
	int ans = 0;
	for (int j = 0; j < R; ++j){
		int i = j-ans;
		while (true){
			long long mid = (arr[(i+j)/2] + arr[(i+j+1)/2]) / 2;
			int itr = min((int)(upper_bound(arr.begin(), arr.end(), mid) - arr.begin()), (int)R-1),
				itl = max((int)(lower_bound(arr.begin(), arr.end(), mid) - arr.begin() - 1), 0);
			itl = max(itl, 0);
			long long dr = psr[j] - psr[itl] - (j - itl) * mid,
					  dl = psl[i] - psl[itr] - (itr - i) * (L - mid);
			if (dl + dr <= B){
				ans = max(ans, j-i+1);
				--i;
				if (i == -1)
					break;
			}
			else break;
		}
	}
	cout << ans << '\n';
return 0;}

