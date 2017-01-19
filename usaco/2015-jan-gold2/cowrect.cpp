#include <bits/stdc++.h>
using namespace std;

struct cow{
	int x, y; char c;
};

bool operator<(const cow &a, const cow &b){
	return a.x < b.x;
}

int main(){
	freopen("cowrect.in", "r", stdin);
	freopen("cowrect.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	static cow a[501];
	for (int i = 0; i < n; ++i)
		cin >> a[i].x >> a[i].y >> a[i].c;
	vector<cow> xtoc[1001];
	for (int i = 0; i < n; ++i)
		xtoc[a[i].x].push_back(a[i]);
	sort(a, a+n);
	int num = 1, area = 0;
	for (int i = 0; i < n; ++i) if (a[i].c != 'G')
		for (int j = i+1; j < n; ++j) if (a[j].c != 'G')
			for (int k = 0; k < 1001; ++k){
				int l = k+1, cnt = 0;
				for (int m = 0; m < xtoc[k].size(); ++m)
					if (min(a[i].y, a[j].y) <= xtoc[k][m].y && xtoc[k][m].y <= max(a[i].y, a[j].y)){
						if (xtoc[k][m].c == 'G') cnt = -0xfffffff;
						else ++cnt;
					}
				if (cnt <= 0) continue;
				for (; l < 1001; ++l){
					int cnt2 = 0;
					for (int m = 0; m < xtoc[l].size(); ++m)
						if (min(a[i].y, a[j].y) <= xtoc[l][m].y && xtoc[l][m].y <= max(a[i].y, a[j].y)){
							if (xtoc[l][m].c == 'G') cnt2 = -0xfffffff;
							else ++cnt2;
						}
					if (cnt2 < 0) break;
					else cnt += cnt2;
					if (cnt > num){
						num = cnt;
						area = abs(a[j].y - a[i].y) * (l-k);
					}
					else if (cnt == num)
						area = min(area, abs(a[j].y - a[i].y) * (l-k));
				}
				k = l;
			}
	cout << num << '\n' << area << '\n';
return 0;}
