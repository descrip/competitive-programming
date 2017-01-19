#include <set>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

const int MAXN = 100;
int N, R, low[MAXN+1], num[MAXN+1], par[MAXN+1], root, rchi, cnt, T = 1;
string atos[MAXN+1];
vector<int> adj[MAXN+1];
map<string,int> stoa;
set<string> art;

void findart(int u){
	low[u] = num[u] = cnt++;
	for (int v : adj[u]){
		if (num[v] == -1){
			par[v] = u;
			if (u == root) ++rchi;
			findart(v);
			if (low[v] >= num[u] && u != root)
				art.insert(atos[u]);
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
		fill(low,low+MAXN+1,-1);
		fill(num,num+MAXN+1,-1);
		fill(par,par+MAXN+1,-1);
		fill(adj,adj+MAXN+1,vector<int>());
		art.clear();
		stoa.clear();
		cnt = 1;
		for (int i = 1; i <= N; ++i){
			cin >> atos[i];
			stoa[atos[i]] = i;
		}
		cin >> R;
		for (int i = 0; i < R; ++i){
			string s, t; cin >> s >> t;
			adj[stoa[s]].push_back(stoa[t]);
			adj[stoa[t]].push_back(stoa[s]);
		}
		for (int i = 1; i <= N; ++i){
			if (num[i] == -1){
				root = i; rchi = 0;
				findart(i);
				if (rchi > 1) art.insert(atos[i]);
			}
		}
		cout << "City map #" << T++ << ": " << art.size() << " camera(s) found\n";
		for (string i : art)
			cout << i << '\n';
		cin >> ws;
		if (cin.peek() != '0') cout << '\n';
	}
return 0;}
