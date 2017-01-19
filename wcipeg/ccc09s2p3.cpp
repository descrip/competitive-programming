#include <bits/stdc++.h>
using namespace std;

void yes(){
	cout << "Yes\n";
	exit(EXIT_SUCCESS);
}
void no(){
	cout << "No\n";
	exit(EXIT_SUCCESS);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int V, E, S, M, G, T; cin >> V >> E >> S >> M >> G >> T;
	static int adj[101][101];
	map<pair<int, int>, int> edgeLook;
	vector<pair<int, int>> edges;
	for (int i = 0; i < E; ++i){
		int x, y, z; cin >> x >> y >> z;
		edges.push_back({x, y});
		edgeLook[make_pair(x, y)] = edgeLook[make_pair(y, x)] = i+1;
		adj[101][101] = z;
	}
	static int sPath[1001], mPath[1001];
	for (int i = 0; i < S; ++i)
		cin >> sPath[i];
	for (int i = S; i <= 1000; ++i)
		sPath[i] = sPath[S-1];
	for (int i = 0; i < M; ++i)
		cin >> mPath[i];
	for (int i = M; i <= 1000; ++i)
		mPath[i] = mPath[M-1];
	static bool isDucked[101];
	for (int i = 0; i < G; ++i){
		int x; cin >> x;
		isDucked[x] = true;
	}

	int sPos = 0, mPos = 0, sCnt = 0, mCnt = 0, sEdge, mEdge;
	for (int t = 0; t < T; ++t){	//TODO: t <= T
		if ((sCnt == 0 && isDucked[sPath[sPos]]) || (mCnt == 0 && isDucked[mPath[mPos]]))
			no();
		if (sCnt == 0)
			sEdge = edgeLook[make_pair(sPath[sPos], sPath[sPos+1])];
		if (mCnt == 0)
			mEdge = edgeLook[make_pair(mPath[mPos], mPath[mPos+1])];
		++sCnt; ++mCnt;
		if (mEdge == sEdge && (sCnt == adj[sPath[sPos]][sPath[sPos+1]] - mCnt))
		if (sCnt == adj[sPath[sPos]][sPath[sPos+1]]){
			sCnt = 0;
			++sPos;
		}
	}
	no();
return 0;}

