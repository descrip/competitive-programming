#include <set>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

const int MAXN = 25;
int N, M, T=1, ncnt, cnt, low[MAXN+1], num[MAXN+1];
string atos[MAXN+1];
set<int> adj[MAXN+1];
map<string,int> stoa;
vector<int> s;
bool vis[MAXN+1];

void scc(int u){
	low[u] = num[u] = cnt++;
	s.push_back(u);
	vis[u] = true;
	for (int v : adj[u]){
		if (num[v] == -1)
			scc(v);
		if (vis[v])
			low[u] = min(low[u],low[v]);
	}
	if (low[u] == num[u]){
		while (true){
			int v = s.back(); s.pop_back();
			cout << atos[v];
			vis[v] = false;
			if (u == v) break;
			cout << ", ";
		}
		cout << '\n';
	}
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	while (true){
		cin >> N >> M;
		if (N == 0) break;
		cnt = 1;
		ncnt = 1;
		fill(low,low+MAXN+1,-1);
		fill(num,num+MAXN+1,-1);
		fill(adj,adj+MAXN+1,set<int>());
		fill(vis,vis+MAXN+1,false);
		stoa.clear();
		s.clear();
		for (int i = 0; i < M; ++i){
			string s, t; cin >> s >> t;
			if (stoa.count(s) == 0){
				stoa[s] = ncnt;
				atos[ncnt++] = s;
			}
			if (stoa.count(t) == 0){
				stoa[t] = ncnt;
				atos[ncnt++] = t;
			}
			adj[stoa[s]].insert(stoa[t]);
		}
		cout << "Calling circles for data set " << T++ << ":\n";
		for (int i = 1; i <= N; ++i)
			if (num[i] == -1)
				scc(i);
		cin >> ws;
		if (cin.peek() != '0')
			cout << '\n';
	}
return 0;}
