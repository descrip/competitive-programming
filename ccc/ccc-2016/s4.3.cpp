#include <bits/stdc++.h>
using namespace std;

struct node{
	int l, l1, r, r1, m;
	node(int a, int b, int c, int d, int e) : l(a), l1(b), r1(c), r(d), m(e) {}
}

int N;
vector<int> V;
node dp[400][400][400];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i){
		int a; cin >> a;
		V.push_back(a);
	}
	/*
	for (int i = 0; i < N-1; ++i)
		if (V[i] == V[i+1])
			dp[i][i+1][1] = node(V[i],-1,-1,V[i],V[i]);
			*/
	for (int l = 0; l < N; ++l)
		for (int r = l+1; r < N; ++r){
			int m = 0;
			for (int i = l; i <= r; ++i)
				m = max(m, V[i]);
			dp[l][r][r-l+1] = m;
		}
	for (int len = 2; len <= N; ++len)
		for (int l = 0; l < N-len; ++l){
			int r = l+len-1;
			if (V[l] == V[r]){
				if (l == r-1)
					dp[l][r][1] = node(l,-1,-1,r,V[l]+V[r]);
				else
					for (int len2 = 1; len2 < len; ++len2)
						for (int l2 = 1
			}
			if (V[r] == dp[l][r-1].r){

			}
			if (V[r] == dp[l][r-1].r1){

			]
			if (V[l] == dp[l+1][r].l){

			}
			if (V[l] == dp[l+1][r].l1){

			}
		}
return 0;}

