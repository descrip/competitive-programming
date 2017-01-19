//Don't use 0xFFFFFFF, use 0x7FFFFFFF

#include <queue>
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

int A, B, N;
vector<int> V[1000];
pair<long long,int> adj[1001][1001];
bool vis[1001];

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	ifstream fin ("cowroute.in");
	fin >> A >> B >> N;
	fill_n(adj[0],1001*1001,make_pair(0x7FFFFFFF,0x7FFFFFFF));
	for (int i = 0; i < N; ++i){
		long long c, n; fin >> c >> n;
		for (int j = 0; j < n; ++j){
			int a; fin >> a;
			for (int k = 0; k < j; ++k)
				adj[V[i][k]][a] = min(adj[V[i][k]][a],{c,j-k});
			V[i].push_back(a);
		}
	}
	priority_queue<pair<long long,pair<int,int>>,
		vector<pair<long long,pair<int,int>>>,
		greater<pair<long long,pair<int,int>>>> q;
	q.push({0,{0,A}});
	ofstream fout ("cowroute.out");
	while (!q.empty()){
		long long dist = q.top().first;
		int tot = q.top().second.first,
			pos = q.top().second.second;
		if (pos == B){
			fout << dist << ' ' << tot << '\n';
			fout.close();
			fin.close();
			return 0;
		}
		q.pop();
		if (vis[pos]) continue;
		vis[pos] = true;
		for (int i = 1; i <= 1000; ++i){
			if (!vis[i] && adj[pos][i].second != 0x7FFFFFFF)
				q.push({dist+adj[pos][i].first,
						{tot+adj[pos][i].second,i}});
		}
	}
	fout << "-1 -1\n";
	fout.close();
	fin.close();
return 0;}
