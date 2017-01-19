#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;
int N, H, tree[MAXN], L[MAXN], R[MAXN];
double P, dp[MAXN][MAXN][2][2];

double solve(int a, int b, bool l, bool r){
	double ret = 0;
	if (a > b)
		return 0;
	else if (dp[a][b][l][r] != -1)
		return dp[a][b][l][r];
	else if (a == b){
		//al
		if (l) ret += P * min(tree[a] - tree[a-1] - H, H);
		else ret += P * min(tree[a] - tree[a-1], H);
		//ar
		if (r) ret += (1-P) * min(tree[b+1] - tree[b], H);
		else ret += (1-P) * min(tree[b+1] - tree[b] - H, H);
	}
	else{
		//ll
		if (l) ret += P/2 * (min(tree[a] - tree[a-1] - H, H) + solve(a+1, b, false, r));
		else ret += P/2 * (min(tree[a] - tree[a-1], H) + solve(a+1, b, false, r));
		//cout << "1 " << a << ' ' << b << ' ' << l << ' ' << r << ' ' << ret << '\n';
		//rr
		if (r) ret += (1-P)/2 * (min(tree[b+1] - tree[b], H) + solve(a, b-1, l, true));
		else ret += (1-P)/2 * (min(tree[b+1] - tree[b] - H, H) + solve(a, b-1, l, true));
		//cout << "2 " << a << ' ' << b << ' ' << l << ' ' << r << ' ' << ret << '\n';
		//lr
		if (R[a] >= b) ret += (1-P)/2 * (tree[b] - tree[a] + min(tree[b+1] - tree[b] - (!r ? H : 0), H));
		else ret += (1-P)/2 * (tree[R[a]] - tree[a] + H + solve(R[a]+1, b, true, r));
		//cout << "3 " << a << ' ' << b << ' ' << l << ' ' << r << ' ' << ret << '\n';
		//rl
		if (L[b] <= a) ret += P/2 * (tree[b] - tree[a] + min(tree[a] - tree[a-1] - (l ? H : 0), H));
		else ret += P/2 * (tree[b] - tree[L[b]] + H + solve(a, L[b]-1, l, false));
		//cout << "4 " << a << ' ' << b << ' ' << l << ' ' << r << ' ' << ret << '\n';
	}
	//cout << a << ' ' << b << ' ' << l << ' ' << r << ' ' << ret << '\n';
	return dp[a][b][l][r] = ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> H >> P;
	for (int i = 1; i <= N; ++i)
		cin >> tree[i];
	sort(tree+1, tree+N+1);
	tree[0] = -0xfffffff;
	tree[N+1] = 0xfffffff;
	for (int i = 1; i <= N; ++i)
		if (tree[i] - tree[i-1] >= H)
			L[i] = i;
		else
			L[i] = L[i-1];
	for (int i = N; i >= 1; --i)
		if (tree[i+1] - tree[i] >= H)
			R[i] = i;
		else
			R[i] = R[i+1];
	for (int i = 0; i < MAXN; ++i)
		for (int j = 0; j < MAXN; ++j)
			for (int k = 0; k < 2; ++k)
				for (int l = 0; l < 2; ++l)
					dp[i][j][k][l] = -1;
	cout << fixed << setprecision(9) << solve(1, N, false, true) << '\n';
return 0;}

