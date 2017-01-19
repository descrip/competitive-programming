//This problem fills me with determination.
#include <bits/stdc++.h>
using namespace std;

struct node{
	int time, x, y;
	bool smell;
	node (int a, int b, int c, bool d) : time(a), x(b), y(c), smell(d) {}
};

bool operator>(const node &a, const node &b){
	return a.time > b.time;
}

int main(){
	freopen("dream.in", "r", stdin);
	freopen("dream.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M; cin >> N >> M;
	static int A[1000][1000];
	for (int y = 0; y < N; ++y)
		for (int x = 0; x < M; ++x)
			cin >> A[y][x];
	priority_queue<node, vector<node>, greater<node>> pq;
	pq.push(node(0, 0, 0, false));
	static bool vis[1000][1000][2];
	while (!pq.empty()){
		node n = pq.top(); pq.pop();
		if (vis[n.y][n.x][n.smell])
			continue;
		vis[n.y][n.x][n.smell] = true;
		//cout << "A " << n.time << ' ' << n.x << ' ' << n.y << ' ' << n.smell << '\n';
		if (n.x == M-1 && n.y == N-1){
			cout << n.time << '\n';
			return 0;
		}
		for (int cy = -1; cy <= 1; cy+=2)
			for (int cx = 0; cx <= 0; cx+=2){
				if (!(0 <= n.x+cx && n.x+cx < M) || !(0 <= n.y+cy && n.y+cy < N))
					continue;
				if (A[n.y+cy][n.x+cx] == 4){
					bool smell = n.smell;
					int time = 0, cx2 = cx*2, cy2 = cy*2;
					while (true){
						//cout << "Y " << n.x << ' ' << cx2 << ' ' << n.y << ' ' << cy2 << '\n';
						if (A[n.y+cy2][n.x+cx2] == 0 || (A[n.y+cy2][n.x+cx2] == 3 && !smell) || !(0 <= n.x+cx2 && n.x+cx2 < M) || !(0 <= n.y+cy2 && n.y+cy2 < N))
							break;
						if (A[n.y+cy2][n.x+cx2] == 2)
							smell = true;
						cy2 += cy;
						cx2 += cx;
						++time;
						if (A[n.y+cy2-cy][n.x+cx2-cx] != 4)
							break;
					}
					pq.push(node(n.time+time+1, n.x+cx2-cx, n.y+cy2-cy, smell));
				}
				else if (A[n.y+cy][n.x+cx] == 3){
					if (n.smell)
						pq.push(node(n.time+1, n.x+cx, n.y+cy, true));
				}
				else if (A[n.y+cy][n.x+cx] == 2)
					pq.push(node(n.time+1, n.x+cx, n.y+cy, true));
				else if (A[n.y+cy][n.x+cx] == 1)
					pq.push(node(n.time+1, n.x+cx, n.y+cy, n.smell));
			}
		for (int cy = 0; cy <= 0; cy+=2)
			for (int cx = -1; cx <= 1; cx+=2){
				if (!(0 <= n.x+cx && n.x+cx < M) || !(0 <= n.y+cy && n.y+cy < N))
					continue;
				if (A[n.y+cy][n.x+cx] == 4){
					bool smell = n.smell;
					int time = 0;
					int cx2 = cx*2, cy2 = cy*2;
					while (true){
						//cout << "X " << n.x << ' ' << cx2 << ' ' << n.y << ' ' << cy2 << '\n';
						if (A[n.y+cy2][n.x+cx2] == 0 || (A[n.y+cy2][n.x+cx2] == 3 && !smell) || !(0 <= n.x+cx2 && n.x+cx2 < M) || !(0 <= n.y+cy2 && n.y+cy2 < N))
							break;
						if (A[n.y+cy2][n.x+cx2] == 2)
							smell = true;
						cy2 += cy;
						cx2 += cx;
						++time;
						if (A[n.y+cy2-cy][n.x+cx2-cx] != 4)
							break;
					}
					pq.push(node(n.time+time+1, n.x+cx2-cx, n.y+cy2-cy, smell));
				}
				else if (A[n.y+cy][n.x+cx] == 3){
					if (n.smell)
						pq.push(node(n.time+1, n.x+cx, n.y+cy, true));
				}
				else if (A[n.y+cy][n.x+cx] == 2)
					pq.push(node(n.time+1, n.x+cx, n.y+cy, true));
				else if (A[n.y+cy][n.x+cx] == 1)
					pq.push(node(n.time+1, n.x+cx, n.y+cy, n.smell));
			}
	}
	cout << -1 << '\n';
return 0;}

