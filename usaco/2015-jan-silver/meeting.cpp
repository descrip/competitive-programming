#include <vector>
#include <fstream>
#include <queue>
#include <iostream>
using namespace std;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int N, M;
	static vector<pair<int,int>> badj[101], eadj[101];
	static bool vis[101][1000001], yes[1000001];
	ifstream fin ("meeting.in");
	fin >> N >> M;
	for (int i = 0; i < M; ++i){
		int a, b, c, d; fin >> a >> b >> c >> d;
		badj[a].push_back({b,c});
		eadj[a].push_back({b,d});
	}
	queue<pair<int,int>> q;
	q.push({0,1});
	while (!q.empty()){
		int u = q.front().second, d = q.front().first; q.pop();
		if (u == N){
			yes[d] = true;
			continue;
		}
		if (vis[u][d]) continue;
		vis[u][d] = true;
		for (auto v : badj[u])
			q.push({d+v.second,v.first});
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0,1});
	fill_n(vis[0],101*1000001,false);
	ofstream fout ("meeting.out");
	while (!pq.empty()){
		int u = pq.top().second, d = pq.top().first; pq.pop();
		if (u == N){
			if (yes[d]){
				fout << d << '\n';
				fout.close();
				fin.close();
				return 0;
			}
			else continue;
		}
		if (vis[u][d]) continue;
		vis[u][d] = true;
		for (auto v : eadj[u])
			pq.push({d+v.second,v.first});
	}
	fout << "IMPOSSIBLE\n";
	fout.close();
	fin.close();
return 0;}
