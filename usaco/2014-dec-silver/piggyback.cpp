#include <fstream>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

const int MAX = 40001;
int B, E, P, N, M, ans = 0xFFFFFFF;
vector<int> adj[MAX];
bool vis[MAX];
int bdist[MAX], edist[MAX], ndist[MAX];

void bfs(int a, int *w){
	queue<int> q;
	q.push(a);
	fill(w,w+MAX,-1);
	w[a] = 0;
	while (!q.empty()){
		int u = q.front(); q.pop();
		for (int v : adj[u])
			if (w[v] == -1){
				w[v] = w[u]+1;
				q.push(v);
			}
	}
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	ifstream fin ("piggyback.in");
	fin >> B >> E >> P >> N >> M;
	for (int i = 0; i < M; ++i){
		int a, b; fin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	bfs(1,bdist); bfs(2,edist); bfs(N,ndist);
	for (int i = 1; i <= N; ++i)
		ans = min(ans,bdist[i]*B+edist[i]*E+ndist[i]*P);
	ofstream fout ("piggyback.out");
	fout << ans << '\n';
	fout.close();
	fin.close();
return 0;}
