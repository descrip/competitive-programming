#include <bits/stdc++.h>
using namespace std;

#define first fi
#define second se

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, T; cin >> N >> T;
	//hor by y ver by x
	set<pair<int, pair<int, int>>> lH, lV;
	dequeue<pair<int, pair<int, pair<int, int>>>> qH, qV;
	vector<pair<int, pair<int, int>>> toAdd;
	int lastX, lastY; cin >> lastX >> lastY;
	int ans = 0;
	for (int n = 0; n < N; ++n){
		int posX, posY; cin >> posX >> posY;
		if (n == qH.front().fi){
			lH.insert(qH.front().second);
			qH.pop_front();
		}
		if (n == qV.front().fi){
			lV.insert(qV.front().second);
			qV.pop_front();
		}
		//vert
		if (posX == lastX){
			int aY = min(lastY, posY), bY = max(lastY, posY);
			qV.push({n+T, {posX, {aY, bY}}});
			auto it = lH.lower_bound(make_pair(aY, make_pair(-1, -1)));
			
			//vert -> hor
			while (it->fi <= bY)
				if (it->se->fi <= posX && posX <= it->se->se){
					++ans;
					if (posX != it->se->fi)
						toAdd.push_back({it->fi, {it->se->fi, posX-1}});
					if (posX != it->se->se)
						toAdd.push_back({it->fi, {posX+1, it->se->se}});
					auto tit = it;
					++it;
					lH.erase(tit);
				}
			while (!toAdd.empty()){
				lH.insert(toAdd.back());
				toAdd.pop_back();
			}

			//vert -> vert
			it = lV.lower_bond(make_pair(posX, make_pair(-1, -1)));
			while (it->fi == posX){
				if (aY <= it->se->fi && it->se->se <= bY){
					ans += it->se->se - it->se->fi + 1;
					if (aY != it->se->fi)
						toAdd.push_back({posX, {aY, it->se->fi}});
					if (bY != it->se->se)
						toAdd.push_back({posX, {it->se->se, bY}});
				}
				else if (it->se->fi <= aY && bY <= it->se->se)
					ans += bY - aY + 1;
			}
		}
		else if (posY == lastY)
			qH.push({n+T, {posY, {min(lastX, posX), max(lastY, posX)}}});
		lastX = posX; lastY = posY;
	}
return 0;}

