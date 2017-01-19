#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
#define fi first
#define se second
int N, K;
int pset[MAXN], srank[MAXN];
vector<pair<int, pair<int, int>>> edges;

int findset(int x){
	return (pset[x] == x ? x : (pset[x] = findset(pset[x])));
}

void unionset(int x, int y){
	/*
	if (findset(x) == findset(y))
		return;
		*/
	int a = findset(x), b = findset(y);
	if (srank[a] > srank[b])
		pset[b] = a;
	else{
		pset[a] = b;
		if (srank[a] == srank[b])
			++srank[b];
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N-1; ++i){
		int x; cin >> x;
		edges.push_back({x, {i, i+1}});
	}
	for (int i = 0; i < N-K; ++i)
		edges.push_back({0, {i, i+K}});
	sort(edges.begin(), edges.end());
	/*
	for (auto p : edges)
		cout << p.fi << ' ' << p.se.fi << ' ' << p.se.se << '\n';
		*/
	fill_n(srank, MAXN, 1);
	for (int i = 1; i <= N; ++i)
		pset[i] = i;
	int ans = 0;
	for (int i = 0; i < edges.size(); ++i)
		if (findset(edges[i].se.fi) != findset(edges[i].se.se)){
			ans += edges[i].fi;
			unionset(edges[i].se.fi, edges[i].se.se);
		}
	cout << ans << '\n';
return 0;}

