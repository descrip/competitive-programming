#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

//TODO: Special case 2, fix 1 first

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M; cin >> N >> M;
	string S; cin >> S;
	int a = 0, b = 0, tot = 0;
	for (int i = 0; i < S.size(); ++i)
		tot += (S[i] == '(' ? 1 : -1);
	if (tot >= 1)
		b += tot;
	else
		a -= tot;
	long long ans = 0;
	/*
	static long long fact[2005];
	fact[1] = fact[0] = 1;
	for (int i = 2; i <= 2004; ++i)
		fact[i] = (i * fact[i-1]) % MOD;
		*/

	static long long ncr[2005][2005];
	for (int i = 0; i < 2005; ++i)
		ncr[i][0] = 1;
	for (int i = 1; i < 2005; ++i)
		for (int j = 1; j < 2005; ++j)
			ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j]) % MOD;

	/*
	for (int i = 0; i <= N-M; ++i){
		int j = N-M-i;
		A = i; B = j;
		if (tot > 0)
			B -= tot;
		else
			A += tot;
		if (A < 0 || B < 0)
			continue;
		long long tmp = ((long long)A*B + B*(B-1)/2 + A*(A-1)/2) % MOD;
		if (tot > 0)
			tmp = (tmp * ncr[j][tot]) % MOD;
		else if (tot < 0)
			tmp = (tmp * ncr[i][-tot]) % MOD;
		cout << A << ' ' << B << ' ' << tmp << '\n';
		ans += tmp;
	}
	*/
	for (int A = 0; A <= N-M; ++A){
		int B = N-M-A;
		long long tmp;
		if (tot >= 1){
			for (int i = 0; i <= B-b; ++i){
				tmp = (ncr[B][b+i] * ncr[A][i]) % MOD;
				cout << A << ' ' << B << ' ' << b+i << ' ' << tmp << '\n';
				ans = (ans + tmp) % MOD;
			}
		}
		else if (tot <= -1){
			for (int i = 0; i <= A-a; ++i){
				tmp += (ncr[A][a+i] * ncr[B][i]) % MOD;
				ans = (ans + tmp) % MOD;
			}
		}
	}

	cout << ans << '\n';
return 0;}

