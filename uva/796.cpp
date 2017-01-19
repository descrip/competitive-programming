#include <set>
#include <utility>
#include <vector>
#include <iostream>
using namespace std;

const int MAXN = 100;
vector<int> adj[MAXN];
int N, low[MAXN], num[MAXN], par[MAXN], rchi, root, cnt;
set<pair<int,int>> ans;

void bri(int u){
	num[u] = low[u] = cnt++;
	for (int v : adj[u]){
		if (num[v] == -1){
			par[v] = u;
			if (u == root) ++rchi;
			bri(v);
			if (low[v] > num[u])
				ans.insert({min(u,v),max(v,u)});
			low[u] = min(low[u],low[v]);
		}
		else if (v != par[u])
			low[u] = min(low[u],num[v]);
	}
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	while (cin >> N){
		cnt = 1;
		fill(low,low+MAXN,-1);
		fill(num,num+MAXN,-1);
		fill(par,par+MAXN,-1);
		fill(adj,adj+MAXN,vector<int>());
		ans.clear();
		for (int i = 0; i < N; ++i){
			int a; cin >> a;
			char c; cin >> c;
			int n; cin >> n;
			cin >> c;
			for (int j = 0; j < n; ++j){
				int b; cin >> b;
				adj[a].push_back(b);
			}
		}
		for (int i = 0; i < N; ++i)
			if (num[i] == -1){
				root = i; rchi = 0;
				bri(i);
			}
		cout << ans.size() << " critical links\n";
		for (auto i : ans)
			cout << i.first << " - " << i.second << '\n';
		cout << '\n';
	}
return 0;}
