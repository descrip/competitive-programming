#include <bits/stdc++.h>
using namespace std;

inline long long dist(long long x1, long long y1, long long x2, long long y2){
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	vector<pair<int,int>> pts (N);
	for (int i = 0; i < N; ++i)
		cin >> pts[i].first >> pts[i].second;
	int X, Q; cin >> X >> Q;
	--X;

	priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
	static bool inf[3000];
	vector<int> hist;
	pq.push(make_pair(0LL,X));
	while (!pq.empty()){
		int t = pq.top().first, x = pq.top().second;
		pq.pop();
		if (inf[x])
			continue;
		inf[x] = true;
		hist.push_back(t);
		for (int i = 0; i < pts.size(); ++i)
			if (!inf[i])
				pq.push(make_pair(t + dist(pts[i].first, pts[i].second, pts[x].first, pts[x].second), i));
	}
	for (int i = 0; i < Q; ++i){
		int t; cin >> t;
		cout << (upper_bound(hist.begin(), hist.end(), t) - hist.begin()) << '\n';
	}
return 0;}

