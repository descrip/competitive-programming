#include <bits/stdc++.h>
using namespace std;

int N, M, K, ans[100001];
list<pair<pair<int, int>, int>> S;

bool isCorner(const pair<int, int> &p) {
	return ((p.first == N || p.first == 0) && (p.second == M || p.second == 0));
}

bool collinear(int x1, int y1, int x2, int y2, int x3, int y3) {
	return ((y2-y1)*(x3-x1) == (x2-x1)*(y3-y1));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < K; ++i) {
		int x, y; cin >> x >> y;
		if (x%2 != y%2) {
			ans[i] = -1;
			continue;
		}
		S.push_back({{x, y}, i});
	}
	pair<int, int> pos = {0, 0};
	int cx = 1, cy = 1;
	bool tick = true;
	int time = 0;
	int cnt = 0;
	while (tick || !isCorner(pos)) {
		//cout << pos.first << ' ' << pos.second << ' ' << cx << ' ' << cy << '\n';
		tick = false;
		int dx = ((cx > 0) ? (N - pos.first) : pos.first), dy = (cy > 0 ? (M - pos.second) : pos.second),
			dd = min(dx, dy);
		//cout << dx << ' ' << dy << ' ' << dd << '\n';
		pair<int, int> newPos = {pos.first+cx*dd, pos.second+cy*dd};
		if (!S.empty()) {
			auto it = S.end(); --it;
			//for (auto it = S.rbegin(); it != S.rend(); ++it) {
			while (true) {
				if (collinear(pos.first, pos.second,
							newPos.first, newPos.second,
							it->first.first, it->first.second)) {
					ans[it->second] = (abs(pos.first - it->first.first) + abs(pos.second - it->first.second)) / 2 + time;
					S.erase(it);
				}
				if (S.empty() || it == S.begin())
					break;
				--it;
			}
		}
		//cout << newPos.first << ' ' << newPos.second << '\n';
		if ((newPos.first == N) || (newPos.first == 0)) cx *= -1;
		else cy *= -1;
		time += (abs(newPos.first - pos.first) + abs(newPos.second - pos.second))/2;
		pos = newPos;
		++cnt;
		if (cnt == 5)
			break;
	}
	for (int i = 0; i < K; ++i)
		cout << ans[i] << '\n';
	return 0;
}

