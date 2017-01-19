#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

vector<pii> graph[100001];
int stores[100001], dist[100001];
bool past[100001];

int main()
{
    fill_n(dist,100001,1 << 30);
    cin.sync_with_stdio(0); cin.tie(0);
    int T,N,M,G;
    cin >> T >> N >> M >> G;
    for (int i=0; i!=G; ++i){
        cin >> stores[i];
    }
    for (int i=0; i!=M; ++i){
        int A,B,L;
        cin >> A >> B >> L;
        graph[A].push_back(make_pair(L,B));
    }
    priority_queue<pii,vector<pii>,greater<pii>> Q;
    Q.push(make_pair(0,0)); //dist, point
    while (!Q.empty())
    {
        int node = Q.top().second, d = Q.top().first; Q.pop();
        if (past[node]){
            continue;
        }
        dist[node] = d;
        past[node] = true;
        for (int i=0; i!=graph[node].size(); ++i){
            int node2 = graph[node][i].second, d2 = graph[node][i].first+d;
            if (!past[node2]){
                Q.push(make_pair(d2,node2));
            }
        }
    }
    int ans = 0;
    for (int i=0; i!=G; ++i){
        if (dist[stores[i]] < T){
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}
