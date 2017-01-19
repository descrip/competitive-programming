#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long N; char C;
    cin >> N >> C;
    --N;
    long long ans = (N-(N%4))*4;
    N %= 4;
    if (N % 2 == 1)
        ans += 7;
    //cout << ans << ' ' << N << '\n';
    string S = "fedabc";
    cout << ans + (S.find(C))+1 << '\n';
	return 0;
}

