#include <set>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

const int MAXN = 20000;
int N, M;
vector<pair<int,int>> adj[MAXN+1];

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; ++i){
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({b,c});
	}
	set<pair<int,int>> s;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0,1});
	int first = -1;
	while (!pq.empty()){
		int d = pq.top().first, p = pq.top().second;
		pq.pop();
		if (p == N){
			if (first == -1)
				first = d;
			else if (first != d){
				cout << d << '\n';
				return 0;
			}
		}
		for (auto i : adj[p])
			if (s.count(make_pair(d+i.second,i.first)) == 0){
				pq.push({d+i.second,i.first});
				s.insert(make_pair(d+i.second,i.first));
			}
	}
	cout << "-1\n";
return 0;}
