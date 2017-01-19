#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

const int MAXN = 100;
int N, low[MAXN+1], num[MAXN+1], par[MAXN+1], rchi, root, cnt, ans;
vector<int> adj[MAXN+1];
bool art[MAXN+1];

void findart(int u){
	low[u] = num[u] = cnt++;
	for (int v : adj[u]){
		if (num[v] == 0){
			par[v] = u;
			if (u == root) ++rchi;
			findart(v);
			if (low[v] >= num[u])
				art[u] = true;
			low[u] = min(low[u],low[v]);
		}
		else if (v != par[u])
			low[u] = min(low[u],num[v]);
	}
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	while (true){
		cin >> N;
		if (N == 0) break;
		fill(adj,adj+MAXN,vector<int>());
		fill(art,art+MAXN,false);
		fill(low,low+MAXN,0);
		fill(num,num+MAXN,0);
		fill(par,par+MAXN,0);
		cnt = 1;
		cin.ignore(256,'\n');
		while (true){
			string s; getline(cin,s);
			istringstream iss (s);
			int a, b; iss >> a;
			if (a == 0) break;
			while (iss >> b){
				adj[a].push_back(b);
				adj[b].push_back(a);
			}
		}
		for (int i = 1; i <= N; ++i)
			if (num[i] == 0){
				root = i; rchi = 0;
				findart(i);
				art[root] = rchi > 1;
			}
		ans = 0;
		for (int i = 1; i <= N; ++i)
			if (art[i])
				++ans;
		cout << ans << '\n';
	}
return 0;}
