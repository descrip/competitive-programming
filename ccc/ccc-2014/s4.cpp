#include <bits/stdc++.h>
using namespace std;

struct pane{
	int x1, y1, x2, y2, t;
} P[1005];

#define fi first
#define se second

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, T; cin >> N >> T;
	vector<int> allX;
	vector<pair<int, int>> allY;
	for (int i = 1; i <= N; ++i){
		cin >> P[i].x1 >> P[i].y1 >> P[i].x2 >> P[i].y2 >> P[i].t;
		allX.push_back(P[i].x1);
		allX.push_back(P[i].x2);
		allY.push_back({P[i].y1, i});
		allY.push_back({P[i].y2, -i});
	}
	sort(allX.begin(), allX.end());
	unique(allX.begin(), allX.end());
	sort(allY.begin(), allY.end());
	long long ans = 0;
	int lastx = 0;
	for (int i = 0; i < allX.size(); ++i){
		int x = allX[i];
		long long tot = 0;
		int lasty = 0;
		for (int j = 0; j < allY.size();){
			auto py = allY[j];
				if (tot >= T && lastx != *allX.begin() && lasty != allY.begin()->fi && lastx != x && lasty != py.fi)
					ans += 1LL * (x-lastx) * (py.fi-lasty);
				if (P[abs(py.se)].x1 < x && x <= P[abs(py.se)].x2)
					tot += 1LL * P[abs(py.se)].t * py.se / abs(py.se);
				lasty = py.fi;
				++j;
				/*
			if (py.fi != allY[j+1].fi){
				if (tot >= T && lastx != *allX.begin() && lasty != allY.begin()->fi && lastx != x && lasty != py.fi)
					ans += 1LL * (x-lastx) * (py.fi-lasty);
				if (P[abs(py.se)].x1 < x && x <= P[abs(py.se)].x2)
					tot += 1LL * P[abs(py.se)].t * py.se / abs(py.se);
				lasty = py.fi;
				++j;
			}
			else{
				if (tot >= T && lastx != *allX.begin() && lasty != allY.begin()->fi && lastx != x && lasty != py.fi)
					ans += 1LL * (x-lastx) * (py.fi-lasty);
				while (j != allY.size()-1 && py.fi == allY[j+1].fi){
					if (P[abs(py.se)].x1 < x && x <= P[abs(py.se)].x2)
						tot += 1LL * P[abs(py.se)].t * py.se / abs(py.se);
					++j;
					py = allY[j];
				}
				if (P[abs(py.se)].x1 < x && x <= P[abs(py.se)].x2)
					tot += 1LL * P[abs(py.se)].t * py.se / abs(py.se);
				lasty = py.fi;
				++j;
			*/
		}
		lastx = x;
	}
	cout << ans << '\n';
	//cout << lastx << ' ' << lasty << ' ' << x << ' ' << py.fi << ' ' << tot << '\n';
return 0;}

