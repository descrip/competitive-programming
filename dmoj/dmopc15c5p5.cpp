#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005, MOD = (1e9)+7;
int N, root, newId[MAXN], cntId = 1;
long long A[MAXN];
pair<int, int> ran[MAXN];
vector<int> adj[MAXN];

long long zmod(long long a, long long b){
	return (a % b + b) % b;
}

long long sum(int i){
	long long ret = 0;
	while (i > 0){
		ret = zmod(ret + A[i], MOD);
		i -= (i & -i);
	}
	/*
	for (; i; i -= (i & -i))
		ret = (ret + A[i]) % MOD;
		*/
	return ret;
}

void add(int i, long long k){
	while (i <= N){
		A[i] = zmod(A[i] + k, MOD);
		i += (i & -i);
	}
	/*
	for (; i <= N; i += (i & -i))
		A[i] = (A[i] + k) % MOD;
	*/
}

int dfsPath(int pos){
	newId[pos] = cntId++;
	int ret = newId[pos];
	for (int v : adj[pos])
		ret = max(ret, dfsPath(v));
	ran[newId[pos]] = {newId[pos], ret};
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout << (-3 % 8) << ' ' << zmod(-3, 8) << '\n';
	cin >> N;
	for (int i = 1; i <= N; ++i){
		int a; cin >> a;
		if (a == 0)
			root = i;
		else
			adj[a].push_back(i);
	}
	dfsPath(root);
	static long long ans[MAXN];
	for (int i = 1; i <= N; ++i){
		int b; cin >> b;
		int a = newId[b];
		long long tmp = zmod(sum(ran[a].second) - sum(ran[a].first-1) + 1LL, MOD);
		ans[b] = tmp;
		add(a, tmp);
	}
	for (int i = 1; i <= N; ++i)
		cout << ans[i] << " \n"[i==N];
return 0;}

