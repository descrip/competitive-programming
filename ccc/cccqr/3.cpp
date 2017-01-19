#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> A;
set<int> X, Y;
map<int, vector<int>> allX, allY;
long long ans = 0;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i){
		int x, y; cin >> x >> y;
		A.push_back({x, y});
		X.insert(x);
		Y.insert(y);
		allX[x].push_back(y);
		allY[y].push_back(x);
		//cout << x << ' ' << y << '\n';
	}
	for (int i : X){
		sort(allX[i].begin(), allX[i].end());
		unique(allX[i].begin(), allX[i].end());
	}
	for (int i : Y){
		sort(allY[i].begin(), allY[i].end());
		unique(allY[i].begin(), allY[i].end());
	}
	for (int i = 0; i < N; ++i){
		int x = A[i].first, y = A[i].second;
		int cntX = lower_bound(allX[x].begin(), allX[x].end(), y) - allX[x].begin(),
			cntY = lower_bound(allY[y].begin(), allY[y].end(), x) - allY[y].begin();
		/*
		cout << x << ' ' << y << ' ' << cntX << ' ' << (allX[x].size() - cntX - 1) << ' ' << cntY << ' ' << (allY[y].size() - cntY -1) << '\n';
		cout << ans << ' ';
		*/
		int oldAns = ans;
		ans += 1LL * cntX * cntY * (allX[x].size() - cntX - 1) * (allY[y].size() - cntY - 1);
		/*
		if (x == 1 && y == -3){
			cout << allY[y].size() << '\n';
			for (int i : allY[y])
				cout << i << ' ' << y << '\n';
		}
		if (ans != oldAns){
			cout << x << ' ' << y << ' ' << ans-oldAns << '\n';
		}
		*/
		//cout << ans << '\n';
	}
	/*
	cout << allY[-3].size() << '\n';
	for (int i : allY[-3])
		cout << i << '\n';
		*/
	cout << ans*2 << '\n';
return 0;}

